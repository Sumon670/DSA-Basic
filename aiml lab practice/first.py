list1 = [0,10,[20,30],40,50,[60,70,80],[90,100,110,120]]
flat=[]
for items in list1:
    if type(items) is list:
        for element in items:
            flat.append(element)
    else:
        flat.append(items)
print(flat)
print(max(flat))
print(min(flat))
flat.sort()
flat.reverse()
print(flat)