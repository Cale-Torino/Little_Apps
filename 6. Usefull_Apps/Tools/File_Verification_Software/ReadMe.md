# File_Verification_Software

_QuickSFV.ini_

```
[QuickSFV]
Signature=1d94ec957516eff
WindowInfo=LAAAAAAAAAABAAAA/////////////////////5UBAAAzAgAAqQUAAFUEAAA=
LVWindowInfo=AwAAAHIAAAByAAAApQAAAA==

```

testing.sfv

```
; Generated by WIN-SFV32 v1.1a (QuickSFV v2.36 Compatibility Mode) on 2023-03-05 at 17:53:57
; http://www.QuickSFV.org
;
;           48  20:38.27 2023-03-04 testing.txt
testing.txt 0A92D0C2
;Q2-1d94ec79fecba30
;Q2-54o7yXpP2QE=
;Q2-gA==

```

testing.md5
```
; Generated by QuickSFV v2.36 on 2023-03-04 at 20:42:09
; http://www.QuickSFV.org
;
;           48  20:38.27 2023-03-04 testing.txt
74a3709ae9fed9f45a5780b6ac1ee4f3 *testing.txt

```

CheckMD5.bat

``` CMD
@echo off
cd /d "%~dp0"
::cd MD5
start QuickSFV.EXE testing.md5
```