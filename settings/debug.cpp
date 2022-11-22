#pragma once

#include <bits/stdc++.h>
using namespace std;

#define Debug(...) __Deb_expand(__LINE__, #__VA_ARGS__, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (n); ++i)

// ---------- Prototype ---------- //
template<typename T>
void __Deb(string name, T val);

template<typename T>
void __Deb(string name, vector<T> vals);

template<typename T, typename U>
void __Deb(string name, pair<T, U> p);

template<typename T, typename U>
void __Deb(string name, map<T, U> mp);

template<typename T>
void __Deb(string name, set<T> st);

template<typename T>
void __Deb(string name, multiset<T> mst);

template<typename T>
void __Deb(string name, complex<T> c);

template<typename T>
void __Deb(string name, stack<T> st);

template<typename T>
void __Deb(string name, queue<T> q);

template<typename T>
void __Deb(string name, priority_queue<T> pq);

template<typename T>
void __Deb(string name, deque<T> dq);

template<typename... T>
void __Deb(string name, tuple<T...> t);

// ---------- Main ---------- //
// Expand
template<class... Arg>
void __Deb_expand(unsigned int line, string name, Arg... arg) {
  cerr << "[DEBUG] Line" << line << ". (" << name << "): ";
  __Deb("", make_tuple(arg...));
  cerr << endl;
}

// 普通の型
template<typename T>
void __Deb(string name, T val) {
  cerr << boolalpha << val;
}

// 配列
template<typename T>
void __Deb(string name, vector<T> vals) {
  int n = vals.size();
  cerr << "{";
  rep(i, n) {
    __Deb("", vals[i]);
    cerr << (i == n - 1 ? "" : ", ");
  }
  cerr << "}";
}

// pair
template<typename T, typename U>
void __Deb(string name, pair<T, U> p) {
  cerr << "(";
  __Deb("", p.first);
  cerr << ", ";
  __Deb("", p.second);
  cerr << ")";
}

// map
template<typename T, typename U>
void __Deb(string name, map<T, U> mp) {
  cerr << "{";
  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    cerr << "";
    __Deb("", itr->first);
    cerr << ": ";
    __Deb("", itr->second);
    cerr << ", ";
  };
  cerr << "\b\b}";
}

// set
template<typename T>
void __Deb(string name, set<T> st) {
  cerr << "[";
  for (auto itr = st.begin(); itr != st.end(); itr++) {
    __Deb("", *itr);
    cerr << (next(itr) == st.end() ? "" : ", ");
  }
  cerr << "]";
}

// multiset
template<typename T>
void __Deb(string name, multiset<T> mst) {
  cerr << "[";
  for (auto itr = mst.begin(); itr != mst.end(); itr++) {
    __Deb("", *itr);
    cerr << (next(itr) == mst.end() ? "" : ", ");
  }
  cerr << "]";
}

// complex
template<typename T>
void __Deb(string name, complex<T> c) {
  cerr << c.real() << "+" << c.imag() << "i";
}

// stack
template<typename T>
void __Deb(string name, stack<T> st) {
  cerr << "[";
  while (!st.empty()) {
    __Deb("", st.top());
    st.pop();
    cerr << (st.empty() ? "" : "; ");
  }
  cerr << "]";
}

// queue
template<typename T>
void __Deb(string name, queue<T> q) {
  cerr << "[";
  while (!q.empty()) {
    __Deb("", q.front());
    q.pop();
    cerr << (q.empty() ? "" : " > ");
  }
  cerr << "]";
}

// priority_queue
template<typename T>
void __Deb(string name, priority_queue<T> pq) {
  cerr << "[";
  while (!pq.empty()) {
    __Deb("", pq.top());
    pq.pop();
    cerr << (pq.empty() ? "" : " > ");
  }
  cerr << "]";
}

// deque
template<typename T>
void __Deb(string name, deque<T> dq) {
  cerr << "[";
  while (!dq.empty()) {
    __Deb("", dq.front());
    dq.pop_front();
    cerr << (dq.empty() ? "" : " <> ");
  }
  cerr << "]";
}

// tuple
template<size_t I, typename T>
void __________DebugTuple(const T& t) {
  if constexpr (I < tuple_size<T>::value) {
    const auto& x = get<I>(t);
    __Deb("", x);
    if constexpr (I + 1 < tuple_size<T>::value) cerr << ", ";
    else
      cerr << "";
    __________DebugTuple<I + 1>(t);
  }
}
template<typename... T>
void __Deb(string name, tuple<T...> t) {
  cerr << "(";
  __________DebugTuple<0>(t);
  cerr << ")";
}