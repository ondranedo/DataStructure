# DataStructure 🛠️

## Info

-Vytvořím v této **repository** datové strukoty, nýbrž třídy kde je lze impelementovat🔑
-Celá repository bude psána v jazyce **C++** a za pomoci **Visual Studia Professional 2022**

[![](https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C++_Logo.svg)](https://en.wikipedia.org/wiki/C++)

---

## Napsané datové struktury

### LinkedList

-naspaný linked list je psán jako **Doubly linked list**

|náv. hodnota|metoda|složistost
|-|-|-|
|**POPPING:**
|data|popHead()     |O(1)|
|data|popTail()     |O(1)|
|data|popIndex(i)   |O(N)|
|**PUSHING:**
|void|pushHead(x)   |O(1)|
|void|pushTail(x)   |O(1)|
|void|pushIndex(i,x)|O(N)|
|**OTHER:**
|data|search(x)     |O(N)|
|void|clear(x)      |O(N)|
|data|size()        |O(1)|

### Stack

-stack je napsnaný s pomocí **LinkeList classy**

|náv. hodnota|metoda|složistost
|-|-|-|
|void|push()|O(1)|
|data|pop()|O(1)|
|data|top()|O(1)|
|bool|isEmpty()|O(1)|
|void|clear()|O(N)|
