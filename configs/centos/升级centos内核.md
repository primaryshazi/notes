# 升级centos内核

1. rpm --import https://www.elrepo.org/RPM-GPG-KEY-elrepo.org

2. rpm -Uvh http://www.elrepo.org/elrepo-release-7.0-2.el7.elrepo.noarch.rpm

3. yum --enablerepo=elrepo-kernel install kernel-ml

4. 修改`/etc/default/grub`并设置`GRUB_DEFAULT=0`

5. grub2-mkconfig -o /boot/grub2/grub.cfg

6. reboot
