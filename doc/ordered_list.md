## ordered_list

```mermaid
classDiagram
    direction LR
    class stream {
        first()
        next()
    }
    <<interface>> stream
    class collection {
        count()
        last()
        prev()
    }
    <<interface>> collection
    stream *-- collection
    class ordered
    <<interface>> ordered
    collection *-- ordered
    class list {
        get()
        at()
    }
    <<interface>> list
    collection *-- list
    class ordered_list
    <<interface>> ordered_list
    ordered *-- ordered_list
    list *-- ordered_list
```

[ordered_list](ordered_list.md) _is a_ [list](list.md) where the item order is significant.
