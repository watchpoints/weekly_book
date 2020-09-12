

@所有人 有木有细心的小伙伴发现咱们的第五期课程已经上线啦！本节课程主题为：DDL 性能优化。

课程概要：
1. TiDB DDL 模块架构概览
2. DDL 性能优化——并行化
3. DDL 性能优化——即时化


视频链接在这里~ 欢迎享用~
https://www.bilibili.com/video/BV1X5411b7ri/

另外是不是有小伙伴对如何认领作业以及提交作业还有疑惑？答应你们的演示视频也同步上线啦！请大家戳这个链接了解详情：https://www.bilibili.com/video/BV1zA411E7t8/











### 预习

#### TiDB 源码阅读系列文章（十七）DDL 源码解析



- 阅读 理解 Google F1: Schema 变更算法

> F1 是 Google 开发的分布式关系数据库，主要服务于 Google 的广告系统，它提供强一致性、高可用性，
>
> 并支持传统 SQL 查询，近来也常常被称之为所谓的 NewSQL。
>
> F1 是构建于 Spanner 之上的。Spanner 是 Google 开发的全球级数据存储引擎，它保证了数据存储的一致性和可用性，还通过 2PC（两阶段提交）提供了分布式事务读写。
>
> 在分析 F1 时，我们可以简单地认为 Spanner 是一个全球分布的 kv 数据库



- 代码：https://github.com/pingcap/tidb/tree/source-code

