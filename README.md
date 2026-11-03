# embedded-lab

嵌入式学习实验仓库。从 C 语言内功到 MCU 固件、RTOS、协议栈与完整项目，每个阶段一个目录，所有实验都有可复现的记录。

## 目录

| 目录 | 内容 | 阶段 |
|---|---|---|
| `01-c-basics` | 指针、位操作、内存对齐、环形缓冲区、编译链接 | P1 |
| `02-mcu-basics` | GPIO / 中断 / 定时器 / 串口 / I2C / ADC，仿真环境完成 | P2 |
| `03-freertos` | 任务管理、队列、信号量、事件组、优先级反转 | P3 |
| `04-protocol-bootloader` | 自定义串口协议、Modbus RTU、Bootloader 原理 | P4 |
| `05-main-project` | 主线项目：FreeRTOS + 双区 Bootloader OTA + Modbus + 低功耗 | P5 |
| `docs` | 学习笔记、时序图、踩坑记录 | 全程 |

## 环境

- 编译器：Keil MDK-ARM 5.14（ARMCC 5.05），PC 端练习用 gcc
- 仿真：Wokwi（外设可视化）、QEMU（RTOS）、Python + pyserial（协议对打）
- 硬件：暂未上板，P5 阶段再补

## 进度

- [x] 环境搭建（Keil / Git / Wokwi）
- [ ] P1 C 语言内功
- [ ] P2 单片机基础
- [ ] P3 FreeRTOS
- [ ] P4 协议栈与 Bootloader
- [ ] P5 主线项目

## 说明

每个实验目录下都有独立的 README，写清：实现了什么、怎么运行、遇到什么问题、怎么解决的。

不是教程搬运，是自己踩出来的记录。
