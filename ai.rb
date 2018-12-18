puts "你好我的朋友！"
loop do
  text = gets
  if text.include?('再见')
    puts "再见我的朋友！"
    break
  end
  puts text.gsub(/\?|？/, '！').gsub('吗', (Random.rand(10) > 3) ? '' : '呀')
end
