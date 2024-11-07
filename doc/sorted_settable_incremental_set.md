## sorted_settable_incremental_set

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
    class set {
        contains()
        contains_all()
        get()
    }
    <<interface>> set
    collection *-- set
    class addable {
        add()
        add_all()
    }
    <<interface>> addable
    collection *-- addable
    class sorted_set 
    <<interface>> sorted_set
    sorted *-- sorted_set
    set *-- sorted_set
    class settable_set {
        set()
    }
    <<interface>> settable_set
    set *-- settable_set
    settable *-- settable_set
    class sorted_settable_set
    <<interface>> sorted_settable_set
    sorted_set *-- sorted_settable_set
    settable_set *-- sorted_settable_set
    class sorted_incremental_set
    <<interface>> sorted_incremental_set
    sorted_set *-- sorted_incremental_set
    incremental_set *-- sorted_incremental_set
    class incremental_set
    <<interface>> incremental_set
    set *-- incremental_set
    addable *-- incremental_set
    class settable_incremental_set
    <<interface>> settable_incremental_set
    settable_set *-- settable_incremental_set
    incremental_set *-- settable_incremental_set
    class sorted_settable_incremental_set
    <<interface>> sorted_settable_incremental_set
    sorted_settable_set *-- sorted_settable_incremental_set
    sorted_incremental_set *-- sorted_settable_incremental_set
    settable_incremental_set *-- sorted_settable_incremental_set
```

[sorted_settable_incremental_set](sorted_settable_incremental_set.md) _is a_ [settable_incremental_set](settable_incremental_set.md)
where the items are sorted.
