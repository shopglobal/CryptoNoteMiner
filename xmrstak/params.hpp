#pragma once

#include "xmrstak/misc/environment.hpp"

#include <string>

namespace xmrstak
{

struct params
{

    static inline params& inst()
    {
        auto& env = environment::inst();
        if(env.pParams == nullptr)
            env.pParams = new params;
        return *env.pParams;
    }

    std::string executablePrefix;
    std::string binaryName;
    bool useAMD;
    bool AMDCache;
    bool useNVIDIA;
    bool useCPU;

    bool poolUseTls = false;
    std::string poolURL;
    bool userSetPwd = false;
    std::string poolPasswd;
    bool userSetRigid = false;
    std::string poolRigid;
    std::string poolUsername;
    bool nicehashMode = false;

    static constexpr int32_t httpd_port_unset = -1;
    static constexpr int32_t httpd_port_disabled = 0;
    int32_t httpd_port = httpd_port_unset;

    std::string currency;

    std::string configFile;
    std::string configFilePools;
    std::string configFileAMD;
    std::string configFileNVIDIA;
    std::string configFileCPU;

    bool allowUAC = true;
    std::string minerArg0;
    std::string minerArgs;

    // block_version >= 0 enable benchmark
    int benchmark_block_version = -1;

    params() :
        executablePrefix(""),
        binaryName("xmr-stak"),
        useAMD(true),
        AMDCache(true),
        useNVIDIA(true),
        useCPU(true),
        configFile("config.txt"),
        configFilePools("pools.txt"),
        configFileAMD("amd.txt"),
        configFileNVIDIA("nvidia.txt"),
        configFileCPU("cpu.txt")
    {}

};

} // namepsace xmrstak
