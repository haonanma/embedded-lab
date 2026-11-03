# keil-first-project

第一个 Keil 工程：STM32F103C8，寄存器点灯（PC13）。

## 目标

- 验证 Keil + 器件包 + CMSIS 工具链能走通
- 编译出可烧录的 `.hex`
- 本阶段不接板子，只验证编译链路

## 环境

| 项 | 版本 |
|---|---|
| Keil MDK | 5.14（ARMCC 5.05） |
| Device | STM32F103C8 |
| DFP | Keil.STM32F1xx_DFP 1.1.0 |
| CMSIS | ARM.CMSIS 4.2.0（RTE CORE 3.40.0） |

## 代码

`main.c` 直接操作寄存器：使能 GPIOC 时钟，把 PC13 配成推挽输出，然后在主循环里翻转电平。PC13 是 Blue Pill 的板载 LED（低电平点亮）。

没有使用 StdPeriph 或 HAL，目的是先看清时钟使能、CRH 配置和 ODR 输出这几步。

## 编译

1. 用 Keil 打开 `keil-first-project.uvprojx`
2. 按 `F7` 编译
3. 生成 `Objects/keil-first-project.hex`

实测结果：

- `0 Error(s), 0 Warning(s)`
- Code=712，RO-data=252，RW-data=0，ZI-data=1632
- hex 大小 2,772 字节

## 踩坑记录

1. **器件列表搜不到 STM32F103C8**：最初装的 DFP 2.3.0 是 CMSIS-Pack 1.4 格式，Keil 5.14 的包管理器只支持到 1.3。换成 DFP 1.1.0（1.2 格式）后正常。
2. **`error: #29: expected an expression`**：`for (volatile uint32_t i = 0; ...)` 在 C90 下不合法。Keil 默认 C90，变量声明要放在块开头，把 `uint32_t i;` 移到循环外即可。
3. **编译通过但没有 hex**：`Options for Target` → `Output` 页要勾选 `Create HEX File`，否则只生成 `.axf`。

## 说明

本目录只负责工具链验证。LED 实际闪烁和下载到板子，留到后续上板阶段确认。
