## mutable_list

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
    class list {
        get()
        at()
    }
    class settable {
        set_item()
    }
    <<interface>> settable
    collection *-- settable
    <<interface>> list
    collection *-- list
    class settable_list {
        set()
    }
    <<interface>> settable_list
    settable *-- settable_list
    list *-- settable_list
    class addable {
        add()
    }
    <<interface>> addable
    collection *-- addable
    class incremental_list
    <<interface>> incremental_list
    addable *-- incremental_list
    list *-- incremental_list
    class removable {
        remove_item()
    }
    <<interface>> removable
    collection *-- removable
    class reducible_list {
        remove()
    }
    <<interface>> reducible_list
    removable *-- reducible_list
    list *-- reducible_list
    class settable_incremental_list
    <<interface>> settable_incremental_list
    settable_list *-- settable_incremental_list
    incremental_list *-- settable_incremental_list
    class settable_reducible_list
    <<interface>> settable_reducible_list
    settable_list *-- settable_reducible_list
    reducible_list *-- settable_reducible_list
    class mutable_list
    <<interface>> mutable_list
    settable_incremental_list *-- mutable_list
    settable_reducible_list *-- mutable_list
```

[mutable_list](mutable_list.md) _is a_ [list](list.md) whose contents may change.
