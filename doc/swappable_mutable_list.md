## swappable_mutable_list

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
    class swappable {
        swap()
    }
    <<interface>> swappable
    ordered *-- swappable
    class list {
        get()
        at()
    }
    <<interface>> list
    collection *-- list
    class settable {
        set_item()
    }
    <<interface>> settable
    collection *-- settable
    class settable_list {
        set()
    }
    <<interface>> settable_list
    list *-- settable_list
    settable *-- settable_list
    class ordered_list
    <<interface>> ordered_list
    ordered *-- ordered_list
    list *-- ordered_list
    class ordered_settable_list
    <<interface>> ordered_settable_list
    ordered_list *-- ordered_settable_list
    settable_list *-- ordered_settable_list
    class insertable {
        insert()
        insert_all()
    }
    <<interface>> insertable
    ordered *-- insertable
    class addable {
        add()
        add_all()
    }
    <<interface>> addable
    collection *-- addable
    class incremental_list
    <<interface>> incremental_list
    addable *-- incremental_list
    list *-- incremental_list
    class ordered_incremental_list
    <<interface>> ordered_incremental_list
    insertable *-- ordered_incremental_list
    ordered_list *-- ordered_incremental_list
    incremental_list *-- ordered_incremental_list
    class removable {
        remove_item()
        remove_all_items()
    }
    <<interface>> removable
    collection *-- removable
    class reducible_list {
        remove()
        remove_all()
    }
    <<interface>> reducible_list
    list *-- reducible_list
    removable *-- reducible_list
    class ordered_reducible_list
    <<interface>> ordered_reducible_list
    ordered_list *-- ordered_reducible_list
    reducible_list *-- ordered_reducible_list
    class settable_incremental_list
    <<interface>> settable_incremental_list
    incremental_list *-- settable_incremental_list
    settable_list *-- settable_incremental_list
    class settable_reducible_list
    <<interface>> settable_reducible_list
    settable_list *-- settable_reducible_list
    reducible_list *-- settable_reducible_list
    class mutable_list
    <<interface>> mutable_list
    settable_incremental_list *-- mutable_list
    settable_reducible_list *-- mutable_list
    class ordered_settable_incremental_list
    <<interface>> ordered_settable_incremental_list
    ordered_incremental_list *-- ordered_settable_incremental_list
    ordered_settable_list *-- ordered_settable_incremental_list
    settable_incremental_list *-- ordered_settable_incremental_list
    class ordered_settable_reducible_list
    <<interface>> ordered_settable_reducible_list
    ordered_settable_list *-- ordered_settable_reducible_list
    ordered_reducible_list *-- ordered_settable_reducible_list
    settable_reducible_list *-- ordered_settable_reducible_list
    class ordered_mutable_list
    <<interface>> ordered_mutable_list
    ordered_settable_incremental_list *-- ordered_mutable_list
    ordered_settable_reducible_list *-- ordered_mutable_list
    mutable_list *-- ordered_mutable_list
    class swappable_list
    <<interface>> swappable_list
    swappable *-- swappable_list
    ordered_list *-- swappable_list
    class swappable_incremental_list
    <<interface>> swappable_incremental_list
    swappable_list *-- swappable_incremental_list
    ordered_incremental_list *-- swappable_incremental_list
    class swappable_settable_list
    <<interface>> swappable_settable_list
    swappable_list *-- swappable_settable_list
    ordered_settable_list *-- swappable_settable_list
    class swappable_reducible_list
    <<interface>> swappable_reducible_list
    swappable_list *-- swappable_reducible_list
    ordered_reducible_list *-- swappable_reducible_list
    class swappable_settable_incremental_list
    <<interface>> swappable_settable_incremental_list
    swappable_incremental_list *-- swappable_settable_incremental_list
    swappable_settable_list *-- swappable_settable_incremental_list
    class swappable_settable_reducible_list
    <<interface>> swappable_settable_reducible_list
    swappable_settable_list *-- swappable_settable_reducible_list
    swappable_reducible_list *-- swappable_settable_reducible_list
    class swappable_mutable_list
    <<interface>> swappable_mutable_list
    swappable_settable_incremental_list *-- swappable_mutable_list
    swappable_settable_reducible_list *-- swappable_mutable_list
    ordered_mutable_list *-- swappable_mutable_list
```

[swappable_mutable_list](swappable_mutable_list.md) _is an_
[ordered_mutable_list](ordered_mutable_list.md) that allows the swapping of
items. 
