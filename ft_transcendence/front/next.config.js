/** @type {import('next').NextConfig} **/
const nextConfig = {
  images: {
    domains: [process.env.NEXT_PUBLIC_HOST, "localhost"],
    remotePatterns: [
      {
        protocol: "https",
        hostname: "cdn.intra.42.fr",
        //port: "",
        // pathname: "",
      },
    ],
  },
};

module.exports = {
  ...nextConfig,
  webpack: (config, { isServer }) => {
    if (isServer) {
      config.externals.push({
        bufferutil: "bufferutil",
        "utf-8-validate": "utf-8-validate",
      });
    }
    return config;
  },
};

//module.exports = nextConfig;
