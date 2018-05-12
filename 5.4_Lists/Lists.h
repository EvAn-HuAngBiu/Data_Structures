#pragma once
//
// 采用头尾链表存储的广义表
// Created by Evan on 2018/5/8.
//

#ifndef INC_5_4_LISTS_LISTS_H
#define INC_5_4_LISTS_LISTS_H

#include <string>

class Lists {
public:
    enum ElemTag {
        ATOM, LIST
    };
    struct GLNode {
        ElemTag tag;
        union {
            char atom;
            struct {
                GLNode *hp, *tp;
            } ptr;    // hp指向表头和表尾
        };
    };

    explicit Lists(const std::string &);    // 构造一个广义表

    virtual ~Lists();    // 销毁广义表

    int depth() const;    // 获取广义表的深度, 对外接口

    void copy(Lists &);    // 复制广义表, 对外接口

private:
    GLNode *GList;

    int depth(GLNode *) const;    // 获取广义表的深度

    void copy(const GLNode *, GLNode *&);    // 复制广义表

    void create(GLNode *&l, std::string s);

    void sever(std::string &, std::string &);

    void destroy(GLNode *);

};

#endif //INC_5_4_LISTS_LISTS_H
