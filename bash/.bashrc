#Search
function rs() {
    grep --color=auto --exclude-dir=.svn -rinse "$1" ./"$2"/*
}


#Shorten the bash user
if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u\[\033[00m\]:\[\033[01;34m\]\W\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\W\$ '
fi
