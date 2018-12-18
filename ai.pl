#!/usr/bin/perl

print "你好我的朋友！\n";
while(true){
    chomp($_ = <STDIN>);
    if(/再见/){
        print "再见我的朋友\n";
        exit;
    }   
    else{
        s/\?|？/\!/g;
        rand(1)>0.3?(s/吗/呀/g):(s/吗//g);
        print "$_\n";
    }
}
