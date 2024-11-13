// 出发点：装饰器是使用了相同的变化方向，如果不同子类具有不同的变化方向该怎么办？
// 假如要实现跨平台的功能，一个是PC端，一个是Mobile端
#include "../../common.h"
#include "Messager.h"
#include "MessagerImp.h"
#include "MobileMessagerImp.h"
#include "PCMessagerImp.h"
#include "MessagerLite.h"

/*
设计模式中的桥模式（Bridge Pattern）之所以得名，是因为它提供了一种方式，使得软件系统的抽象部分（Abstraction）与实现部分（Implementation）可以相对独立地变化。这就像在一座桥上，桥的两侧分别代表了抽象部分和实现部分，桥身则连接了两者，使得它们可以独立地发展和变化，而不需要彼此紧密耦合。
具体来说，桥模式的核心思想是通过组合而不是继承来实现不同维度的变化。在桥模式中，“桥”主要体现在将两个角色之间的继承关系改为聚合关系，也就是将抽象化与实现化之间的强关联改换成弱关联。这样，抽象部分和实现部分就可以通过组合/聚合关系来连接，而不是通过继承关系。这种设计使得抽象部分和实现部分可以独立地扩展和变化，而不会影响到对方。
桥模式通常用于处理那些具有多个独立变化维度的场景。例如，在处理图形界面时，图形和颜色可能是两个独立变化的维度。通过桥模式，可以将这两个维度拆分开来，使得它们可以独立地扩展和变化，而不会影响到彼此。这样的设计符合开闭原则，使得系统更加灵活和可扩展。
因此，桥模式中的“桥”代表了抽象部分和实现部分之间的连接和通信机制，它使得两者可以独立地变化，从而提高了软件系统的灵活性和可维护性。这是桥模式得名的根本原因。
*/

int main(){
    cout << "桥模式下，需要构造1（基类）+m（平台）+n（业务抽象）" << endl;
    cout << "由于平台、业务是两个变化的方向，因此拆分基类为两个Messager, MessagerImp" << endl;
    cout << "且Messager持有MessagerImp的指针，这样可以直接多态调用，只要二者均被继承" << endl;
    cout << "前者主要是基于业务等级的实现，后者是基于平台的实现" << endl;


    // 要想进行动态类型转化，需要共有继承，public 继承
    MessagerImp* messagerImp = new MobileMessagerImp();
    Messager* messager = new MessagerLite(messagerImp);
    string username = "name";
    string password = "pswd";
    // 以下即为Mobile和Lite的组合
    messager->Login(username, password);
}