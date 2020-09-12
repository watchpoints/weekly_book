

### 准备数据
/data/tidb/tiup/tidb-deploy/tidb-4000/log

mysql -h 127.0.0.1 -P 4000 -u root  -p 

explain select * from teacher where age >=18


CREATE TABLE `teacher` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `age` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4;

INSERT  INTO teacher(id,NAME,age) VALUES (1,'seven',18);
INSERT  INTO teacher(id,NAME,age) VALUES (2,'qingshan',20);


#### 16 | “order by”是怎么工作的？
https://www.zybuluo.com/adamhand/note/1414482

~~~
CREATE TABLE `t` (
  `id` int(11) NOT NULL,
  `city` varchar(16) NOT NULL,
  `name` varchar(16) NOT NULL,
  `age` int(11) NOT NULL,
  `addr` varchar(128) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `city` (`city`)
) ENGINE=InnoDB;

现在要查询城市是“杭州”的所有人名字，并且按照姓名排序返回前 1000 个人的姓名、年龄
select city,name,age from t where city='杭州' order by name limit 1000  ;
alter table t add index city_user(city, name);
alter table t add index city_user_age(city, name, age);

~~~