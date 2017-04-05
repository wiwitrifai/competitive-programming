n = gets.to_i
n = n-1
s = gets.chomp
last = '#'
cnt = 0
for i in (0..n)
    if s[i] != last then
        if "oe".count(last) > 0 and cnt == 2 then
            print last
        end
    end
    if "aeiouy".count(s[i]) > 0 then
        if s[i] == last then
            cnt = cnt + 1
        else
            print s[i]
            cnt = 1
        end
    else
        print s[i]
        cnt = 1
    end
    last = s[i]
end
if "oe".count(last) > 0 and cnt == 2 then
    print last
end
print "\n"