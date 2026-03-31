# AI 赋能智能硬件创客训练营 · 课程仓库

> 深圳大学工业设计系 × 柴火创客学院 | 2026 春季

## 这是什么？

这是 AI 赋能智能硬件创客训练营的课程开发仓库。学生使用 AI CLI 工具（OpenCode 等）在本仓库中完成硬件编程项目。

AI 工具启动后会自动读取 `CLAUDE.md`，获得完整的硬件平台信息和开发规范，从而能够根据你的需求描述直接生成可编译运行的代码。

## 快速开始

只需安装 OpenCode（AI CLI 工具），然后让 AI 帮你完成其余所有准备：

```bash
# 1. 启动 OpenCode
opencode

# 2. 告诉 AI 完成环境搭建
> 请帮我完成以下准备工作：
> 1. 检查 git 是否安装，如果没有请指导我安装
> 2. 克隆课程仓库 https://github.com/mouseart2025/szu-ai-maker-2026.git
> 3. 检查 PlatformIO CLI 是否安装，没有请安装
> 4. 进入 examples/01-led-blink，编译并上传到开发板
> 5. 读取 CLAUDE.md，告诉我这个项目的硬件平台和模块清单

# 3. LED 闪了 = 环境 OK。创建自己的项目：
> 请帮我从 templates/grove-project 模板创建一个新项目叫 my-project
# 然后编辑 requirements.md，描述你的需求，让 AI 开始编程
```

<details>
<summary>手动方式（不使用 AI 工具）</summary>

```bash
git clone https://github.com/mouseart2025/szu-ai-maker-2026.git
cd szu-ai-maker-2026/examples/01-led-blink
pio run -t upload        # 编译并上传
pio device monitor       # 串口监视器
```
</details>

## 仓库结构

```
szu-ai-maker-2026/
├── CLAUDE.md               # AI 上下文（硬件信息 + 开发规范）
├── hardware/               # 硬件参考文档
│   ├── grove-beginner-kit.md
│   ├── wio-terminal.md
│   └── xiao-esp32s3.md
├── examples/               # 已验证的示例项目
│   ├── 01-led-blink/
│   ├── 02-button-led/
│   └── 03-sensor-oled/
├── templates/              # 项目模板
│   └── grove-project/
└── students/               # 学生项目目录
```

## 硬件平台

| 课次 | 设备 | 说明 |
|:---:|---|---|
| L1-L2 | Grove Beginner Kit | 11 模块一体板，Seeeduino Lotus 主控 |
| L3-L4 | Wio Terminal | 带彩色屏幕的微控制器 |
| L5-L6 | XIAO ESP32S3 Sense | 拇指大小，内置摄像头 |

## 开发环境

- **PlatformIO CLI** — 编译与上传
- **OpenCode** — AI CLI 编程工具
- **Git** — 版本管理

## 工作流

```
写 requirements.md  →  AI 读需求 + 生成代码  →  编译上传  →  验收  →  迭代
```

## 讲师

冯磊、胡慧东 | 柴火创客空间
