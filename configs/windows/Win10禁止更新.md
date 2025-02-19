# Win10禁止更新

## 禁止服务

1. services.msc

2. `Windows Update`服务选择禁用

3. 恢复项置为无操作

## 关闭组件

1. gpedit.msc

2. 计算机配置 -> 管理模板 -> Windows组件 -> Windows更新

3. `配置自动更新`置为已禁用

4. `删除使用所有Windows更新功能的访问权限`置为已启用

5. `允许自动更新立即安装` 置为已禁用

## 禁用计划任务

1. taskschd.msc

2. 任务计划程序库 -> Microsoft -> Windows -> WindowsUpdate

3. 计划任务均置为禁用

## 关闭注册表

1. regedit.msc

2. HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\UsoSvc

3. `Start`16进制值修改为4

4. `FailureActions`0010与0018行第五个置为00
