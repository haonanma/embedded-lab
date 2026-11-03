# pyserial 虚拟串口收发

P0 的第四个节点。目标是在不接任何硬件的前提下，让 PC 端脚本完整走一遍「打开串口 → 写数据 → 读回来」，为后面所有串口协议实验打地基。

## 环境

| 项 | 版本 / 路径 |
|---|---|
| Python | 3.12.10（`C:\Users\19382\AppData\Local\Programs\Python\Python312`） |
| pyserial | 3.5 |
| 虚拟串口 | pyserial 内置 `loop://`，不需要 com0com |

## 代码

见 `loopback_test.py`：

```python
import serial

with serial.serial_for_url("loop://", timeout=1) as s:
    s.write(b"hello pyserial\n")
    print(s.readline().decode().strip())
```

`loop://` 是 pyserial 自带的回环端：写进去的字节会原样读回来，所以不需要装虚拟串口驱动，也不用管理员权限。

## 运行

```
python loopback_test.py
```

## 验收标准

终端输出：

```
hello pyserial
```

说明写入和读回的是同一份数据，链路通了。

## 踩坑记录

1. **`python --version` 返回 exit 49 / 弹 Microsoft Store**
   这是 Windows 自带的 `python.exe` 占位符，不是真的 Python。用 winget 装完 python.org 版后重开终端即可；若仍被拦截，去「设置 → 应用 → 高级应用设置 → 应用执行别名」关掉 `python.exe` 和 `python3.exe`。

2. **为什么要用 `loop://` 而不是 com0com**
   com0com 要装内核驱动、可能遇到签名问题，P0 阶段只是想验证“能发能收”，`loop://` 足够。等 P4 需要两个程序互相通信时再上 com0com。

3. **`decode()` 不能省**
   pyserial 读出来是 `bytes`，直接 print 会带 `b'...'`。要显示成正常字符串得用 `.decode()`（默认 UTF-8）。
