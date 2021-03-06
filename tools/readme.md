
# windows 工具安装说明
> 此说明的存在意义在于我下次在新电脑上安装，不用到处找软件的下载链接，自动脚本不好搞，想用最新的软件版本，强迫症

> 在 windows 7 下面安装经常使用的软件，在向 windows 10 迁移的时，在 windows 7 上安装的软件可以直接在 Windows 10 上打开，只是有些软件需要运行库支持，这其中有个难点就是不知道这个软件需要的是那个版本的运行库。

> 所以软件都是手动安装，太无聊了。因为不是自动化安装，所以下面的路径和脚本都是固定死的，哎！

> 哈哈，向现实屈服吧，写自己下载脚步，下次吧，嘻嘻！

## 基础工具
1. 一个可以通过命令管理软件的平台 --> [msys2](https://www.msys2.org/)
2. 一个好用也好看的终端 --> [ConEmu](https://conemu.github.io/)
3. 一个可以不用鼠标的编辑器 --> [vim](https://github.com/vim/vim-win32-installer)

### msys2
> windows 自己带的 `cmd` 和 `powershell` 不会用，所以使用 `msys2` 做一个平台，一个自动化的平台。

1. 下载 [msys2](https://www.msys2.org/) ，其实[清华大学源](https://mirrors.tuna.tsinghua.edu.cn)更好用！
    - [清华大学源 msys2(x86\_64)](https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/msys2-x86_64-latest.exe)
    - [清华大学源 msys2(i686)](https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/msys2-i686-latest.exe)

2. 傻瓜“下一步”安装 `msys2` ，[修改软件源为“清华大学源”](https://mirrors.tuna.tsinghua.edu.cn/help/msys2/)；

3. Update!!! [pacman 常用命令](https://www.jianshu.com/p/ea651cdc5530)

4. 安装 `git, gcc_x64`
```bash
$ pacman -S git mingw-w64-x86_64-gcc
```

5. 克隆 `this` 并且运行部署脚步
```bash
# example
$ git clone https://github.com/geekyes/learn_notes.git
$ start ./learn_notes/tools/workspace/tools/bin/cj_develop_env.bat
```
> `cj_develop_env.bat` 是从 `autoas/as` 的[部署脚步](https://github.com/autoas/as/blob/master/Console.bat)修改而来。

### ConEmu
> [配置文件](https://github.com/geekyes/learn_notes/blob/master/tools/workspace/tools/conemu/ConEmu.xml)

- [ConEmu](https://conemu.github.io/)

### vim
> 自己使用的插件需要 python 所以需要留意 vim 编译的 python 版本是多少，不然 vim 会启动闪退

0. 注：`msys2` 的 `python` 运行有问题，所以需要手动安装 [python3](https://www.python.org/downloads/) ，主要是配合 `vim` 作扩展，所以需要查看 [vim 编译依赖](https://github.com/vim/vim-win32-installer/blob/master/README.md) 
1. [vim 完整编译好的版本下载地址](https://github.com/vim/vim-win32-installer/releases)
2. 源码 tag 工具
    - [universal ctags](https://github.com/universal-ctags/ctags)
    - [gnu global](https://www.gnu.org/software/global/)
    - [universal ctags download](https://github.com/universal-ctags/ctags-win32/releases) && [gnu global download](http://adoxa.altervista.org/global/)
    - vim 的自动生成 tag 插件 [/gen\_tags.vim](https://github.com/jsfaint/gen_tags.vim)
3. 各种自动补全的插件
    - c/c++ 补全不卡，体验好点的 [YouCompleteMe X64](https://github.com/snakeleon/YouCompleteMe-x64) && [X86](https://github.com/snakeleon/YouCompleteMe-x86)
    - python 补全 [ncm2-jedi](https://github.com/ncm2/ncm2-jedi)
    - path 补全 [ncm2-path](https://github.com/ncm2/ncm2-path)


## MCU 工具
    - [arm series open toolchains(rt-thread Env)](https://www.rt-thread.org/page/download.html)
    - [C51 series open toolchains(sdcc)](http://sdcc.sourceforge.net/)
    - [open Debug tool(openOCD)](http://openocd.org/)
