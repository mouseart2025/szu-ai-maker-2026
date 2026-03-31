# AI 赋能智能硬件创客训练营 · 课程仓库

> 深圳大学工业设计系 × 柴火创客学院 | 2026 春季

## 这是什么？

这是 AI 赋能智能硬件创客训练营的课程开发仓库。学生使用 AI CLI 工具（OpenCode 等）在本仓库中完成硬件编程项目。

AI 工具启动后会自动读取 `CLAUDE.md`，获得完整的硬件平台信息和开发规范，从而能够根据你的需求描述直接生成可编译运行的代码。

## 快速开始

```bash
# 1. Clone 仓库
git clone https://github.com/xxx/szu-ai-maker-2026.git
cd szu-ai-maker-2026

# 2. 验证环境（以 LED 闪烁为例）
cd examples/01-led-blink
pio run -t upload        # 编译并上传到 Seeeduino Lotus
pio device monitor       # 打开串口监视器

# 3. 创建自己的项目
cd ../..
cp -r templates/grove-project my-project
cd my-project
# 编辑 requirements.md，然后启动 AI 工具开始编程
```

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
