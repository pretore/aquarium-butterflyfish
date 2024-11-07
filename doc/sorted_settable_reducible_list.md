## sorted_settable_reducible_list

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
    class sorted_reducible_list
    <<interface>> sorted_reducible_list
    sorted_list *-- sorted_reducible_list
    reducible_list *-- sorted_reducible_list
    class settable_reducible_list
    <<interface>> settable_reducible_list
    settable_list *-- settable_reducible_list
    reducible_list *-- settable_reducible_list
    class sorted_settable_reducible_list
    <<interface>> sorted_settable_reducible_list
    sorted_settable_list *-- sorted_settable_reducible_list
    sorted_reducible_list *-- sorted_settable_reducible_list
    settable_reducible_list *-- sorted_settable_reducible_list
```

[sorted_settable_reducible_list](sorted_settable_reducible_list.md) _is a_ 
[settable_reducible_lis](settable_reducible_list.md) where the items are sorted.
