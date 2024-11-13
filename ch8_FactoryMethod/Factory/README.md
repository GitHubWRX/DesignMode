### 背景
ch5中，文件分割器中我们使用了观察者模式，但是可能存在其他的分割器
将FileSpliter直接编码到使用它的类中，看起来并不灵活，因为可能有很多不同的Spliter

### 修改点
ch8的Normal即为ch5的Observer模式，这样再进行工厂修改
根据外部Context判断，传入SpliterFactory工厂类，作为m_factory存入MainFrom
m_factory->CreateSpliter()，会得到实际的XXX_spliter，然后多态调用其split()方法即可


