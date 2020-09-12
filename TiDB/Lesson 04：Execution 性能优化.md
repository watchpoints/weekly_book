

# Lesson 04：Execution 性能优化.

[任务地址](https://github.com/pingcap/tidb/issues?q=is%3Aopen+is%3Aissue+label%3Ahigh-performance+label%3Asig%2Fexecution)

分值：600
题目描述：
目前，聚合函数的内存追踪有待完善；
认领一个聚合函数，并根据 issue 内描述完成他的内存追踪 issues/19369


分值：3000
题目描述：
	认领一个还未进行滑动窗口优化的聚合函数，并优化他 issues/12967 


分值：3000
题目描述：
	认领一个还未 inline projection 优化的算子，并优化他 issues/14428 


分值：3000
题目描述：
	认领一个还未被实现的聚合函数，并实现他 issues/7623 


分值：600
题目描述：
认领一个表达式函数的问题，并修复 issues/11223


分值：6600
题目描述：
	使用已有的 Shuffle 算子，实现并行化 Stream Aggregate  issues/9244


分值：6600
题目描述：
	使用已有的 Shuffle 算子，实现并行化 Merge Join issues/14441 


分值：600
题目描述：
选取任意一个执行器或表达式相关的 bug issue 并修复它
help-wanted issues of execution
help-wanted issues of expressions

* 相关 issue 链接可从 PPT 直接获取


https://github.com/pingcap/tidb/issues/18693





## 代码学习



~~~go

// Chunk 本质上是 Column 的集合
type column struct {
	length     int //用来表示这个 Column 有多少行数据。
	nullCount  int //用来表示这个 Column 中有多少 NULL 数据。
	nullBitmap []byte//用来存储这个 Column 中每个元素是否是 NULL
	offsets    []int32 
    //给变长的 Column 使用，存储每个数据在 data 这个 slice 中的偏移量。
	data       []byte //存储具体的数据
	elemBuf    []byte
    //给定长的 Column 使用，当需要读或者写一个数据的时候，使用它来辅助 encode 和 decode
}
appendInt64()
AppendString

// Chunk stores multiple rows of data in Apache Arrow format.
// See https://arrow.apache.org/docs/memory_layout.html
// Values are appended in compact format and can be directly accessed without decoding.
// When the chunk is done processing, we can reuse the allocated memory by resetting it.
type Chunk struct {
	columns []*column
	// numVirtualRows indicates the number of virtual rows, witch have zero columns.
	// It is used only when this Chunk doesn't hold any data, i.e. "len(columns)==0".
	numVirtualRows int
}

// AppendInt64 appends a int64 value to the chunk.
func (c *Chunk) AppendInt64(colIdx int, i int64) {
	c.columns[colIdx].appendInt64(i)
}


// Executor executes a query.
type Executor interface {
	Next(goctx.Context) (Row, error) 
    //每次函数调用只返回一行数据
	Close() error
	Open(goctx.Context) error
	Schema() *expression.Schema
	retTypes() []*types.FieldType
	supportChunk() bool
	newChunk() *chunk.Chunk
	NextChunk(goCtx goctx.Context, chk *chunk.Chunk) error
}  //每次函数调用返回一批数据，数据量由一个叫 tidb_max_chunk_size 的 session 变量来控制，默认是 1024 行

TiDB 源码阅读系列文章（九）Hash Join
什么是 Hash Join
Hash Join 的基本定义可以参考维基百科：Hash join。简单来说，A 表和 B 表的 Hash Join 需要我们选择一个 Inner 表来构造哈希表，然后对 Outer 表的每一行数据都去这个哈希表中查找是否有匹配的数据。

~~~



- TiDB 源码阅读系列文章（二十二）Hash Aggregation

~~~go
在 SQL 中，聚合操作对一组值执行计算，并返回单个值。
TiDB 实现了 2 种聚合算法：Hash Aggregation 和 Stream Aggregation。

select avg(b) from t group by a

~~~




## FQA
- https://asktug.com/t/topic/36992
- 如何理解每次查询获取一行

![Row](https://download.pingcap.com/images/blog-cn/tidb-source-code-reading-10/3.jpeg)![TiDB 2.0 执行框架](https://download.pingcap.com/images/blog-cn/tidb-source-code-reading-10/5.png)




# 参考
- 揭秘 TiDB 新优化器： Cascades Planner 原理解析
- TiDB 源码阅读系列文章（六）Select 语句概览
- ​	[Go夜读 第 47 期 TiDB 源码阅读之 Executor](https://www.bilibili.com/video/av55403428/) --OK 40分钟
- https://docs.qq.com/pdf/DSkNaZW9hTXNqWXVH 
- 数据库内核杂谈（四）：执行模式 --- 0% 