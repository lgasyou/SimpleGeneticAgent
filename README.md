# 八数字解法

> 基于遗传算法的八数字解法

项目使用轮盘式选择、单点交叉算法，实现了简单的遗传算法，并使用该算法解决了八数字问题。

## 使用方法
使用以下命令一键构建：
```bash
./build_and_run.sh
```

## 运行参数
修改以下变量即可自定义运行参数：
```C++
// 种群大小
constexpr int population = 20;

// 最大迭代数
constexpr int maxGeneration = 1000;

// 交叉概率
constexpr float crossoverRate = 0.7f;

// 变异概率
constexpr float mutationRate = 0.001f;

// 染色体长度
constexpr int chromosomeLength = 20;
```

## 项目结构
1. Agent 目录下包括遗传算法相关实现（遗传算法智能体，个体，选择、交叉算法，以及智能体访问器）；
2. Environment 目录下包括遗传算法交互的环境实现（通用的环境模块，八数字游戏等）。
3. Main 为程序入口；
4. Random 包含全局公用的随机数生成引擎单例；
5. build_and_run.sh：自动化发行版程序的构建与运行。

## 算法
```
初始化遗传算法群体
while 智能体迭代未结束（未取得可行解，且未达到最大迭代数）：
    使用选择算法（轮盘式）选择下一代个体
    使用交叉算法（单点）对群体进行
    使用变异概率对个体各个部位进行变异
    计算群体的适应度
    增加当前代数
```
