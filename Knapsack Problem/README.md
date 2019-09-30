uva10819.cpp 這題是01背包問題只用一維陣列的版本

第27行for(int j=wt; j>=weight; --j) 要從後面更新下來的原因是因為要避免前面的更新影響後面的更新(因28、29行wet[j-weight]會用到前面陣列的數值) 。

如果是uva10819_twodimensionarray.cpp用二維陣列就沒有這個問題，要從前面更新或後面都可以。

在uva10819_twodimensionarray.cpp中的

int left=wet[j][i];

int right=wet[j - weight][i] + cost;

wet[j][i+1] = max(left,right);

j指的是還有多少空間(重量)可使用

i指的是將第幾個物品放入的情況

而wet[j][i+1] = max(wet[j][i],wet[j - weight][i] + cost);指的就是不取跟取的情況，不取的話可用空間不變，所以wet[j][i]中的j不變，情況與上一個物品放入的情況一樣。

再來看右邊wet[j - weight][i] + cost，如果要拿則剩下的空間減少，所以j - weight，而且背包中價值增加，所以+cost。

