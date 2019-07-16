all = 0
for i = 1, 13 do
  if i ~= myself then
    all = all ~ colors[i]
  end
end

bool = false
if myself == 13 then
  for i = 0, 12 do
    if ((all >> i) & 1) == 1 then
      bool = not bool
    end
  end
else
  bool = ((all >> (myself-1)) & 1) == 1
end

hands = raise(bool)

answer = 0
for bit = 0, 11 do 
  if (bit+1 ~= myself) then
    res = 0
    for i = 1, 13 do
      if i ~= bit+1 and i ~= myself then
        res = res ~ (colors[i] & (1 << bit))
      end
    end
    if hands[bit+1] then
      res = res ~ (1 << bit)
    end
    answer = answer ~ res
  end
end
if myself ~= 13 then
  all = all ~ answer ~ colors[13]
  for bit = 0, 11 do
    if ((all >> bit) & 1) == 1 then
      answer = answer ~ (1 << (myself-1))
    end
  end
  if hands[13] then
    answer = answer ~ (1 << (myself-1))
  end
end