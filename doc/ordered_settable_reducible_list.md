## ordered_settable_reducible_list

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
    class settable_reducible_list
    <<interface>> settable_reducible_list
    settable_list *-- settable_reducible_list
    reducible_list *-- settable_reducible_list
    class ordered_settable_reducible_list
    <<interface>> ordered_settable_reducible_list
    ordered_settable_list *-- ordered_settable_reducible_list
    ordered_reducible_list *-- ordered_settable_reducible_list
    settable_reducible_list *-- ordered_settable_reducible_list
```

[ordered_settable_reducible_list](ordered_settable_reducible_list.md) _is a_ 
[settable_reducible_list](settable_reducible_list.md) 
where the item order is significant.
