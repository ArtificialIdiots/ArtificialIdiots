print("你好我的朋友! ")
while( true )
do
 io.write("> ")
 usersay = io.read()
 if (string.find(usersay, "再见") or string.find(usersay, "晚安"))
 then
  break
 end
 aisay = string.gsub(usersay,"吗","呀")
 aisay = string.gsub(aisay,"?","!")
 aisay = string.gsub(aisay,"？","! ")
 aisay = string.gsub(aisay,"你","我")
print(aisay)
end
print("再见我的朋友! ")
