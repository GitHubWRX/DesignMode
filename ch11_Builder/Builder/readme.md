### 修改逻辑

此处将Normal文件夹中的House拆分为3部分：
1. House本身，主要包含了属性的**实物对象**
2. HouseBuilder，具体的每个步骤的**操作者**
3. HouseDirector，指挥HouseBuilder按照一定顺序建造，并且返回最终House实例的**指挥者** 