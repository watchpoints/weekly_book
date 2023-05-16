

# 书单

# 2023



### 第一个资料：论文  Paxos 三篇

### 推荐语：

提到Paxos算法，我们不得不首先来介绍下Paxos算法的作者Leslie Lamport（莱斯利·兰伯特，http://www.lamport.org/）及其对计算机科学尤其是分布式计算领域的杰出贡献。作为2013年的新科图灵奖得主，Lamport是计算机科学领域一位拥有杰出成就的传奇人物，其先后多次荣获ACM和IEEE以及其他各类计算机重大奖项。Lamport对时间时钟、面包店算法、拜占庭将军问题以及Paxos算法的创造性研究，极大地推动了计算机科学尤其是分布式计算的发展，全世界无数工程师得益于他的理论，其中Paxos算法的提出，正是Lamport多年的研究成果。

说起Paxos理论的发表，还有一段非常有趣的历史故事。Lamport早在1990年就已经将其对Paxos算法的研究论文《**The PartTime Parliament**》(http://research.microsoft.com/en-us/um/people/lamport/pubs/lamport-paxos.pdf)提交给ACM TOCS Jnl.的评审委员会了，但是由于Lamport“创造性”地使用了故事的方式来进行算法的描述，导致当时委员会的工作人员没有一个能够正确地理解他对算法的描述，时任主编要求Lamport使用严谨的数据证明方式来描述该算法，否则他们将不考虑接受这篇论文。遗憾的是，Lamport并没有接收他们的建议，当然也就拒绝了对论文的修改，并撤销了对这篇论文的提交。在后来的一个会议上，Lamport还对此事耿耿于怀：“为什么这些搞理论的人一点幽默感也没有呢？”



幸运的是，还是有人能够理解Lamport那公认的令人晦涩的算法描述的。1996年，来自微软的Butler Lampson在WDAG96上提出了重新审视这篇分布式论文的建议，在次年的WDAG97上，麻省理工学院的Nancy Lynch也公布了其根据Lamport的原文重新修改后的《**Revisiting the Paxos Algorithm**》(http://research.microsoft.com/en-us/um/people/blampson/60-PaxosAlgorithm/Acrobat.pdf)，“帮助”Lamport用数学的形式化术语定义并证明了Paxos算法。于是在1998年的ACM TOCS上，这篇延迟了9年的论文终于被接受了，也标志着Paxos算法正式被计算机科学接受并开始影响更多的工程师解决分布式一致性问题。



后来在2001年，Lamport本人也做出了让步，这次他放弃了故事的描述方式，而是使用了通俗易懂的语言重新讲述了原文，并发表了《**Paxos Made Simple**》(http://research.microsoft.com/en-us/um/people/lamport/pubs/paxos-simple.pdf)——当然，Lamport甚为固执地认为他自己的表述语言没有歧义，并且也足够让人明白Paxos算法，因此不需要数学来协助描述，于是整篇文章还是没有任何数学符号。好在这篇文章已经能够被更多的人理解，相信绝大多数的Paxos爱好者也都是从这篇文章开始慢慢进入了Paxos的神秘世界。



由于Lamport个人自负固执的性格，使得Paxos理论的诞生可谓一波三折。关于Paxos理论的诞生过程，后来也成为了计算机科学领域被广泛流传的学术趣事。

​                                   ——引用《从Paxos到Zookeeper 分布式一致性原理与实践》

作者：架构随笔
链接：https://juejin.cn/post/6844903683788898312
来源：稀土掘金
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



资料：

- https://www.microsoft.com/en-us/research/wp-content/uploads/2016/11/Acrobat-3.pdf
- http://research.microsoft.com/en-us/um/people/lamport/pubs/lamport-paxos.pdf
- http://research.microsoft.com/en-us/um/people/blampson/60-PaxosAlgorithm/Acrobat.pdf



工具：

- https://www.deepl.com/translator
- https://www.chatpdf.com/[访问不了]
- 
