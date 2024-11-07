## swappable_settable_reducible_list

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
    class settable_list {
        set()
    }
    <<interface>> settable_list
    list *-- settable_list
    settable *-- settable_list
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
    class ordered_list
    <<interface>> ordered_list
    ordered *-- ordered_list
    list *-- ordered_list
    class ordered_settable_list
    <<interface>> ordered_settable_list
    ordered_list *-- ordered_settable_list
    settable_list *-- ordered_settable_list
    class swappable_list
    <<interface>> swappable_list
    swappable *-- swappable_list
    ordered_list *-- swappable_list
    class swappable_settable_list
    <<interface>> swappable_settable_list
    swappable_list *-- swappable_settable_list
    ordered_settable_list *-- swappable_settable_list
    class ordered_reducible_list
    <<interface>> ordered_reducible_list
    ordered_list *-- ordered_reducible_list
    reducible_list *-- ordered_reducible_list
    class swappable_reducible_list
    <<interface>> swappable_reducible_list
    swappable_list *-- swappable_reducible_list
    ordered_reducible_list *-- swappable_reducible_list
    class settable_reducible_list
    <<interface>> settable_reducible_list
    reducible_list *-- settable_reducible_list
    settable_list *-- settable_reducible_list
    class ordered_settable_reducible_list
    <<interface>> ordered_settable_reducible_list
    ordered_reducible_list *-- ordered_settable_reducible_list
    ordered_settable_list *-- ordered_settable_reducible_list
    settable_reducible_list *-- ordered_settable_reducible_list
    class swappable_settable_reducible_list
    <<interface>> swappable_settable_reducible_list
    swappable_reducible_list *-- swappable_settable_reducible_list
    swappable_settable_list *-- swappable_settable_reducible_list
    ordered_settable_reducible_list *--swappable_settable_reducible_list
```

[swappable_settable_reducible_list](swappable_settable_reducible_list.md) _is an_
[ordered_settable_reducible_list](ordered_settable_reducible_list.md) where the items may be swapped.
