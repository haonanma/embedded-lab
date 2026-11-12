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

### P0 工具链与环境（2026-11-03 完成）

- [x] 01 Keil MDK 编译通过第一个 STM32F103C8 工程，`0 Error / 0 Warning`，产出 `.hex`
- [x] 02 Wokwi 在线仿真：点灯 + 串口打印，截图已归档
- [x] 03 Git 建仓、首次提交、推送到 GitHub
- [x] 04 Python + pyserial 打通 PC 端串口收发（当前验证的是 `loop://` 自环）

### 后续阶段

- [ ] P1 C 语言内功 ← **当前位置：第 05 项 指针基础**
- [ ] P2 单片机基础
- [ ] P3 FreeRTOS
- [ ] P4 协议栈与 Bootloader
- [ ] P5 主线项目

> P0 收口笔记见 [`docs/open-questions.md`](docs/open-questions.md)。
> 已知的待补项：`volatile` 空循环优化问题留到 P1-09 亲手复现；真实 COM 口对打留到 P4 之前补齐。

## 说明

每个实验目录下都有独立的 README，写清：实现了什么、怎么运行、遇到什么问题、怎么解决的。

不是教程搬运，是自己踩出来的记录。
