# cmake_host_system_information

``` cmake
# 查询系统信息
# NUMBER_OF_LOGICAL_CORES       主机逻辑核数目，cpu线程数
# NUMBER_OF_PHYSICAL_CORES      主机物理核数目，cpu内核数
# HOSTNAME                      主机名字
# FQDN                          域名
# TOTAL_VIRTUAL_MEMORY          虚拟内存总大小
# AVAILABLE_VIRTUAL_MEMORY      虚拟内存可用大小
# TOTAL_PHYSICAL_MEMORY         物理内存总大小
# AVAILABLE_PHYSICAL_MEMORY     物理内存可用大小
# IS_64BIT                      是否是64位
# HAS_FPU                       cpu是否支持浮点运算
# HAS_MMX                       cpu是否支持MMX
# HAS_MMX_PLUS                  cpu是否支持MMX PLUS
# HAS_SSE                       cpu是否支持 SSE
# HAS_SSE2                      cpu是否支持 SSE2
# HAS_SSE_FP                    cpu是否支持 SSE　FP
# HAS_SSE_MMX                   cpu是否支持SSE MMX
# HAS_AMD_3DNOW                 是否是支持3D NOW技术的AMD cpu
# HAS_AMD_3DNOW_PLUS            是否是支持3D NOW PLUS技术的AMD cpu
# HAS_IA64                      是否是IA64指令集处理器
# HAS_SERIAL_NUMBER             cpu是否有序列号
# PROCESSOR_SERIAL_NUMBER       cpu 序列号查询
# PROCESSOR_NAME                cpu名称
# PROCESSOR_DESCRIPTION         cpu的全部说明
# OS_NAME                       操作系统名字
# OS_RELEASE                    操作系统子类型
# OS_VERSION                    操作系统版本
# OS_PLATFORM                   运行平台信息
cmake_host_system_information(RESULT VALUE_RESULT QUERY HOSTNAME)
```
