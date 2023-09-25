"use client";

import React, { useEffect, useState } from "react";
import {
  Box,
  Flex,
  Text,
  useToast,
  Divider,
  Avatar,
  Stack,
  HStack,
  Spacer,
} from "@chakra-ui/react";
import Cookies from "js-cookie";
import {
  GoCircleSlash,
  GoMute,
  GoSquirrel,
  GoStar,
  GoStarFill,
  GoX,
} from "react-icons/go";
import BaseIconButton from "@/ui/Button/IconButton";
import { set } from "react-hook-form";
import ChannelInput from "@/ui/Input/ChannelInput";
import { fetchAsyncToBackEnd } from "@/utils/lib/fetchAsyncToBackEnd";

interface Props {
  channelId: number;
  channel: { [key: string]: any };
  members: any[];
  setMembers: React.Dispatch<React.SetStateAction<any[]>>;
  bannedMembers: any[];
  setBannedMembers: React.Dispatch<React.SetStateAction<any[]>>;
}

const ChannelMemberlList: React.FC<Props> = ({
  channelId,
  channel,
  members,
  setMembers,
  bannedMembers,
  setBannedMembers,
}) => {
  const toast = useToast();
  const [tmpMembers, setTmpMembers] = React.useState<any[]>([]);
  const [error, setError] = useState<Error | null>(null);

  if (error) throw error;

  useEffect(() => {
    setTmpMembers(members);
  }, [members]);

  async function getChannelMembers() {
    try {
      const res = await fetchAsyncToBackEnd(`/channel/${channelId}/member`);
      if (!res) return;
      const resJson = await res.json();
      setMembers(resJson);
    } catch (err: any) {
      setError(err);
    }
  }

  useEffect(() => {
    getChannelMembers();
  }, []);

  async function banMember(memberId: number) {
    try {
      const res = await fetchAsyncToBackEnd(
        `/channel/${channelId}/banned-member?memberId=${memberId}`,
        {
          method: "POST",
        }
      );
      return res;
    } catch (err: any) {
      setError(err);
    }
  }

  async function banMemberHandler(member: any) {
    if (confirm(`정말로 ${member.user.name} 유저를 차단하시겠습니까?`)) {
      const res = await banMember(member.user.id);
      if (!res) return;

      if (res.status > 299) {
        toast({
          title: "차단에 실패하였습니다.",
          status: "error",
          duration: 9000,
          isClosable: true,
        });
      } else {
        toast({
          title: `${member.user.name} 유저가 차단되었습니다.`,
          status: "success",
          duration: 9000,
          isClosable: true,
        });
        setMembers(members.filter((m) => m.user.id !== member.user.id));
        setBannedMembers([...bannedMembers, member]);
      }
    }
  }

  async function kickMember(memberId: number) {
    try {
      const res = await fetchAsyncToBackEnd(
        `/channel/${channelId}/kicked-member?memberId=${memberId}`,
        {
          method: "DELETE",
        }
      );
      return res;
    } catch (err: any) {
      setError(err);
    }
  }

  async function kickMemberHandler(member: any) {
    if (confirm(`정말로 ${member.user.name} 유저를 쫓아내겠습니까?`)) {
      const res = await banMember(member.user.id);
      if (!res) return;

      if (res.status > 299) {
        toast({
          title: "차단에 실패하였습니다.",
          status: "error",
          duration: 9000,
          isClosable: true,
        });
      } else {
        toast({
          title: `${member.user.name} 유저를 채널에서 쫓아냈습니다.`,
          status: "success",
          duration: 9000,
          isClosable: true,
        });
        setMembers(members.filter((m) => m.user.id !== member.user.id));
      }
    }
  }

  async function adminMember(memberId: number) {
    try {
      const res = await fetchAsyncToBackEnd(
        `/channel/${channelId}/admin?memberId=${memberId}`,
        {
          method: "PATCH",
        }
      );
      return res;
    } catch (err: any) {
      setError(err);
    }
  }

  async function adminMemberHandler(member: any) {
    const res = await adminMember(member.user.id);
    if (!res) return;

    const resJson = await res.json();
    const message = member.isAdmin ? "관리자 해제" : "관리자 등록";

    if (res.status > 299) {
      toast({
        title: resJson.message,
        status: "error",
        duration: 9000,
        isClosable: true,
      });
    } else {
      toast({
        title: message,
        status: "success",
        duration: 9000,
        isClosable: true,
      });
    }
    members.map((m) => {
      if (m.user.id === member.user.id) {
        m.isAdmin = !m.isAdmin;
      }
    });
    setMembers([...members]);
  }

  async function searchChannelMemberHandler(
    event: React.ChangeEvent<HTMLInputElement>
  ) {
    if (event.target.value === "") {
      setTmpMembers(members);
    } else {
      const tmp: any[] = [];
      members.map((m) => {
        if (m.user.name.includes(event.target.value)) {
          tmp.push(m);
        }
      });
      setTmpMembers(tmp);
    }
  }

  return (
    <Box>
      <ChannelInput
        placeholder="search channel member"
        onChange={(event) => {
          searchChannelMemberHandler(event);
        }}
      />
      <Stack spacing={2} mt={4} px={2}>
        {tmpMembers.map((member, index) => (
          <React.Fragment key={member.user.id}>
            <HStack>
              <Avatar
                size="sm"
                src={member.user.image}
                name={member.user.name}
                mr={4}
              />
              <Text fontSize="md">{member.user.name}</Text>
              <Spacer />
              {channel.ownerId !== member.user.id && (
                <Box>
                  <BaseIconButton
                    aria-label="admin"
                    icon={member.isAdmin ? <GoStarFill /> : <GoStar />}
                    size="xs"
                    ml={2}
                    onClick={() => adminMemberHandler(member)}
                  />
                  <BaseIconButton
                    aria-label="admin"
                    icon={<GoX />}
                    size="m"
                    ml={2}
                    onClick={() => kickMemberHandler(member)}
                  />
                  <BaseIconButton
                    aria-label="admin"
                    icon={<GoCircleSlash />}
                    size="xs"
                    ml={2}
                    onClick={() => banMemberHandler(member)}
                  />
                </Box>
              )}
            </HStack>
            {index !== members.length && ( // 변경된 부분: 마지막 요소 제외
              <Divider borderColor="#414147" />
            )}
          </React.Fragment>
        ))}
      </Stack>
    </Box>
  );
};

export default ChannelMemberlList;
