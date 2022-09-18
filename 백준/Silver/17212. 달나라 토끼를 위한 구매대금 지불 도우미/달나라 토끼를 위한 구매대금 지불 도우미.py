def sco(coin):
    if coin<0:
        return 0
    co=[0,1,1,2,2,1,2,1]
    if coin>7:
        for x in range(8,coin+1):
            co.append(1+min(co[x-1],co[x-2],co[x-5],co[x-7]))
    return co[coin]
N=int(input())
print(sco(N))

