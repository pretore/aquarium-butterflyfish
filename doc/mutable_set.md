## mutable_set

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
    class removable {
        remove_item()
        remove_all_items()
    }
    <<interface>> removable
    collection *-- removable
    class settable_set {
        set()
    }
    <<interface>> settable_set
    settable *-- settable_set
    set *-- settable_set
    class incremental_set
    <<interface>> incremental_set
    set *-- incremental_set
    addable *-- incremental_set
    class reducible_set {
        remove()
        remove_all()
        retain_all()
    }
    <<interface>> reducible_set
    removable *-- reducible_set
    set *-- reducible_set
    class settable_incremental_set
    <<interface>> settable_incremental_set
    settable_set *-- settable_incremental_set
    incremental_set *-- settable_incremental_set
    class settable_reducible_set
    <<interface>> settable_reducible_set
    settable_set *-- settable_reducible_set
    reducible_set *-- settable_reducible_set
    class mutable_set
    <<interface>> mutable_set
    settable_incremental_set *-- mutable_set
    settable_reducible_set *-- mutable_set
```

[mutable_set](mutable_set.md) _is a_ [set](set.md) whose contents may change.
