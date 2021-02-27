# 在Windows中启用UTF-8

## 为什么要用UTF-8

如果在Windows中要表示多国语言或emoji等特殊字符，一般都要用UNICODE(也就是UTF-16)，所有字符占2字节空间（包括ASCII字符），所以会浪费很多资源，UTF8很好地解决了这个问题，这是Windows 10 1903 (2019 更新) 的一项新功能

查看原文：<https://docs.microsoft.com/zh-cn/windows/uwp/design/globalizing/use-utf8-code-page>

## 启用UTF-8

### 编写 C/C++ Win32 UTF-8 应用程序

#### 关闭UNICODE

删除预定义 UNICODE _UNICODE 或在源文件前加入

``` C
#ifdef UNICODE
#undef UNICODE
#endif
#ifdef _UNICODE
#undef _UNICODE
#endif
```

源文件所有 -W Api 替换成 -A Api，(包括函数名, 类名, 宏名)

例如

MessageBox 或 MessageBoxW 都改成 MessageBoxA

WNDCLASSEX 或 WNDCLASSEXW 都改成 WNDCLASSEXA

MAKEINTRESOURCE 或 MAKEINTRESOURCEW 都改成 MAKEINTRESOURCEA

所有wchar_t都改成char

#### 改用UTF-8代码页

源文件需要用UTF-8编码保存, 不能是"UTF-8 with BOM", 否则编译器会把内容转换成ANSI

资源文件(rc文件)和resource.h还是要用"UTF-16 LE"保存, 因为资源编译器不支持UTF-8

#### 清单中加入元素，告诉系统这是UTF-8应用程序

``` xml
<assembly manifestVersion="1.0" xmlns="urn:schemas-microsoft-com:asm.v1">
  <assemblyIdentity type="win32" name="..." version="6.0.0.0"/>
  <application>
    <windowsSettings>
      <activeCodePage xmlns="http://schemas.microsoft.com/SMI/2019/WindowsSettings">UTF-8</activeCodePage>
    </windowsSettings>
  </application>
</assembly>
```

最后生成，运行，可以达到和UNICODE程序相同的效果，但是资源占用会减少

## 说明

这种方法不适用与控制台程序，如果要控制台显示多国语言，还是要用UNICODE

这是一个UNICODE控制台程序的示例
<https://github.com/Windowsist/ConsoleApplication>
