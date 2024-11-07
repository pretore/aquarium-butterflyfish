## ordered_settable_incremental_set

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
    class settable {
        set_item()
    }
    <<interface>> settable
    collection *-- settable
    class insertable {
        insert()
        insert_all()
    }
    <<interface>> insertable
    ordered *-- insertable
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
    class settable_set {
        set()
    }
    <<interface>> settable_set
    set *-- settable_set
    settable *-- settable_set
    class incremental_set
    <<interface>> incremental_set
    set *-- incremental_set
    addable *-- incremental_set
    class ordered_set
    <<interface>> ordered_set
    ordered *-- ordered_set
    set *-- ordered_set
    class ordered_settable_set
    <<interface>> ordered_settable_set
    ordered_set *-- ordered_settable_set
    settable_set *-- ordered_settable_set
    class ordered_incremental_set
    <<interface>> ordered_incremental_set
    insertable *-- ordered_incremental_set
    ordered_set *-- ordered_incremental_set
    incremental_set *-- ordered_incremental_set
    class settable_incremental_set
    <<interface>> settable_incremental_set
    incremental_set *-- settable_incremental_set
    settable_set *-- settable_incremental_set
    class ordered_settable_incremental_set
    <<interface>> ordered_settable_incremental_set
    ordered_incremental_set *-- ordered_settable_incremental_set
    ordered_settable_set *-- ordered_settable_incremental_set
    settable_incremental_set *-- ordered_settable_incremental_set
```

[ordered_settable_incremental_set](ordered_settable_incremental_set.md) _is a_ 
[settable_incremental_set](settable_incremental_set.md) where the item order is significant.
