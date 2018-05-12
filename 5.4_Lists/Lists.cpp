//
// Created by Evan on 2018/5/8.
//

#include "Lists.h"

Lists::Lists(const std::string &l) {
    create(GList, l);
}

Lists::~Lists() {
    destroy(GList);
}

void Lists::destroy(Lists::GLNode *l) {
    if (!l) {
        return;
    }
    if (l->tag == ATOM || (!l->ptr.tp && !l->ptr.hp)) {
        // 空表或原子节点时直接删除
        delete l;
        return;
    }
    auto p = l;
    while (p) {
        auto q = p->ptr.tp;    // q保存当前处理结点的表尾地址
        destroy(p->ptr.hp);    // 销毁p的表头结点
        delete p;    // 销毁当前结点
        p = q;    // 当前结点下移
    }
}

int Lists::depth() const {
    // 获取当前广义表的深度
    return depth(GList);
}

int Lists::depth(GLNode *L) const {
    if (!L) {
        // 空表深度为1
        return 1;
    }
    if (L->tag == ATOM) {
        // 原子类型, 递归结束
        return 0;
    }
    int max = 0;
    for (auto pp = L; pp; pp = pp->ptr.tp) {
        // 遍历广义表或子表
        // 条件：表尾存在
        int dep = depth(pp->ptr.hp);
        if (dep > max) {
            max = dep;
        }
    }
    return max + 1;
}

void Lists::copy(const GLNode *src, GLNode *&dst) {
    if (!src) {
        // 空广义表
        dst = nullptr;
        return;
    }
    // 设置表头元素的类型
    dst = new GLNode();
    dst->tag = src->tag;
    if (src->tag == ATOM) {
        // 只有一个元素的表
        dst->atom = src->atom;
    } else {
        copy(src->ptr.hp, dst->ptr.hp);    // 复制表头元素
        copy(src->ptr.tp, dst->ptr.tp);    // 复制表尾元素
    }
}

void Lists::copy(Lists &l) {
    copy(this->GList, l.GList);
}

void Lists::sever(std::string &str, std::string &hstr) {
    // 分离表头和表尾元素
    // 表头元素保存在hstr中返回, 表尾元素保存在str中
    unsigned index = 0, left = 0;    // index记录位置索引, left记录未匹配的左括号数
    unsigned len = str.length();
    char ch = str[index];
    while (index < len && !(left == 0 && ch == ',')) {
        if (ch == '(') {
            left++;
        } else if (ch == ')') {
            left--;
        }
        ch = str[++index];
    }
    if (index < len) {
        hstr = str.substr(0, index);
        str = str.substr(index + 1, len - index - 1);
    } else {
        hstr = str.substr(0, str.length());
        str = "";
    }
}

void Lists::create(Lists::GLNode *&l, std::string s) {
    if (s == "()") {
        // 空表
        l = nullptr;
    } else {
        l = new GLNode();    // 分配存储空间
        if (s.length() == 1) {
            // 只有一个元素
            l->tag = ATOM;
            l->atom = s[0];
        } else {
            l->tag = LIST;
            auto p = l;
            GLNode *q;
            s = s.substr(1, s.length() - 2); // 脱外层括号
            do {
                std::string hstr;
                sever(s, hstr);    // 分离表头、表尾元素
                create(p->ptr.hp, hstr);    // 表头元素递归建立结点
                q = p;
                if (!s.empty()) {
                    p = new GLNode();
                    p->tag = LIST;
                    q->ptr.tp = p;
                }
            } while (!s.empty());
            q->ptr.tp = nullptr;
        }
    }
}





