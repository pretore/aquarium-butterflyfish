## sorted_settable_incremental_list

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
    class sorted {
        ceiling()
        floor()
        higher()
        lower()
    }
    <<interface>> sorted
    collection *-- sorted
    class settable {
        set_item()
    }
    <<interface>> settable
    collection *-- settable
    class list {
        get()
        at()
    }
    <<interface>> list
    collection *-- list
    class sorted_list
    <<interface>> sorted_list
    sorted *-- sorted_list
    list *-- sorted_list
    class settable_list {
        set()
    }
    <<interface>> settable_list
    list *-- settable_list
    settable *-- settable_list
    class sorted_settable_list
    <<interface>> sorted_settable_list
    sorted_list *-- sorted_settable_list
    settable_list *-- sorted_settable_list
    class addable {
        add()
        add_all()
    }
    <<interface>> addable
    collection *-- addable
    class incremental_list
    <<interface>> incremental_list
    list *-- incremental_list
    addable *-- incremental_list
    class sorted_incremental_list
    <<interface>> sorted_incremental_list
    sorted_list *-- sorted_incremental_list
    incremental_list *-- sorted_incremental_list
    class settable_incremental_list
    <<interface>> settable_incremental_list
    settable_list *-- settable_incremental_list
    incremental_list *-- settable_incremental_list
    class sorted_settable_incremental_list
    <<interface>> sorted_settable_incremental_list
    sorted_settable_list *-- sorted_settable_incremental_list
    sorted_incremental_list *-- sorted_settable_incremental_list
    settable_incremental_list *-- sorted_settable_incremental_list
```

[sorted_settable_incremental_list](sorted_settable_incremental_list.md) _is a_ 
[settable_incremental_list](settable_incremental_list.md) where the items are 
sorted.
