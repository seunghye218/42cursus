"use client";

import {
  Box,
  Divider,
  FormControl,
  FormLabel,
  IconButton,
  Modal,
  ModalBody,
  ModalCloseButton,
  ModalContent,
  ModalFooter,
  ModalHeader,
  ModalOverlay,
  Radio,
  RadioGroup,
  Stack,
  useDisclosure,
  useToast,
} from "@chakra-ui/react";
import BaseButton from "../Button/Button";
import { GoPlus } from "react-icons/go";
import Cookies from "js-cookie";
import { useState } from "react";
import { EChannelType } from "@/app/(chat)/channel/types/EChannelType";
import BaseInput from "../Input/Input";
import { fetchAsyncToBackEnd } from "@/utils/lib/fetchAsyncToBackEnd";

export interface CreateChannelModalProps {
  channels: any;
  setChannels: any;
  joinedChannels: any;
  setJoinedChannels: any;
}

export default function CreateChannelModal({
  channels,
  setChannels,
  joinedChannels,
  setJoinedChannels,
  ...props
}: CreateChannelModalProps) {
  const { isOpen, onOpen, onClose } = useDisclosure();
  const [channelName, setChannelName] = useState<string>("");
  const [channelPassword, setChannelPassword] = useState<string>("");
  const [channelType, setChannelType] = useState<string>(
    EChannelType[EChannelType.public]
  );
  const toast = useToast();
  const [error, setError] = useState<Error | null>(null);

  if (error) throw error;

  async function createChannel() {
    try {
      const res = await fetchAsyncToBackEnd(`/channel`, {
        method: "POST",
        body: JSON.stringify({
          name: channelName,
          password: channelPassword,
          type: EChannelType[channelType as keyof typeof EChannelType],
        }),
      });
      return res;
    } catch (err: any) {
      setError(err);
    }
  }

  async function handleCreateChannel() {
    if (
      channelType === EChannelType[EChannelType.protected] &&
      !channelPassword
    ) {
      toast({
        title: "Channel creation error!",
        description: "Please enter a password for the channel",
        status: "error",
        duration: 3000,
        isClosable: true,
      });
      return;
    }

    const res = await createChannel();
    if (!res) return;

    const resJson = await res.json();

    if (res.status > 299) {
      toast({
        title: resJson.message,
        status: "error",
        duration: 3000,
        isClosable: true,
      });
      return;
    }

    if (
      EChannelType[resJson.type] === EChannelType[EChannelType.public] ||
      EChannelType[resJson.type] === EChannelType[EChannelType.protected]
    ) {
      setChannels([...channels, resJson]);
    }
    setJoinedChannels([...joinedChannels, resJson]);
    setChannelName("");
    setChannelPassword("");
    onClose();
  }

  return (
    <Box>
      <IconButton
        aria-label="채널 추가"
        icon={<GoPlus />}
        bg="#414147"
        borderRadius={"8px"}
        textColor="white"
        _hover={{
          background: "#191919",
        }}
        onClick={onOpen}
      />

      <Modal isOpen={isOpen} onClose={onClose}>
        <ModalOverlay />
        <ModalContent
          mt={40}
          p={4}
          border="#A0A0A3 3px solid"
          boxShadow={"7px 7px black"}
          borderRadius="0"
          bg="#29292D"
          {...props}
        >
          <ModalHeader mx={1} py={3}>
            Create New Channel
          </ModalHeader>
          <ModalCloseButton size="sm" m={1} />
          <ModalBody
            mx={4}
            py={6}
            borderTop={"#A0A0A3 1px solid"}
            borderBottom={"#A0A0A3 1px solid"}
          >
            <Box marginBottom={3}>
              <FormControl>
                <FormLabel>Channel Name</FormLabel>
                <BaseInput
                  placeholder="Enter channel name"
                  value={channelName}
                  onChange={(e) => setChannelName(e.target.value)}
                />
              </FormControl>
              <Divider my={4} borderColor="#A0A0A3" />
              <FormControl mt={2}>
                <FormLabel>Channel Type</FormLabel>
                <RadioGroup
                  onChange={(value) => setChannelType(value)}
                  value={channelType}
                >
                  <Stack direction="row" spacing={6}>
                    {Object.keys(EChannelType)
                      .filter(
                        (key) =>
                          isNaN(Number(key)) &&
                          key !== EChannelType[EChannelType.direct]
                      )
                      .map((key, i) => (
                        <Radio key={i} value={key}>
                          {key}
                        </Radio>
                      ))}
                  </Stack>
                </RadioGroup>
                {channelType === EChannelType[EChannelType.protected] && (
                  <FormControl mt={4}>
                    <Divider my={4} borderColor="#A0A0A3" />
                    <FormLabel>Channel Password</FormLabel>
                    <BaseInput
                      placeholder="Enter channel password"
                      value={channelPassword}
                      onChange={(e) => setChannelPassword(e.target.value)}
                    />
                  </FormControl>
                )}
              </FormControl>
            </Box>
          </ModalBody>
          <ModalFooter>
            <BaseButton
              flex="1"
              fontSize={14}
              mr={2}
              my={2}
              size="sm"
              text="create"
              onClick={handleCreateChannel}
            />
          </ModalFooter>
        </ModalContent>
      </Modal>
    </Box>
  );
}
