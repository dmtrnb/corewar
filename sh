ptf=~/Desktop/corewar/players/*
vm=~/Desktop/vm/corewar
cor=~/Desktop/new_core/corewar

for file in $ptf;
do
ls $file
$vm $file > 0;
$cor $file > 1;
diff 0 1;
done
