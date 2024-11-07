## swappable_set

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
    class set {
        contains()
        contains_all()
        get()
    }
    <<interface>> set
    collection *-- set
    class ordered_set
    <<interface>> ordered_set
    set *-- ordered_set
    ordered *-- ordered_set
    class swappable_set 
    <<interface>> swappable_set
    swappable *-- swappable_set
    ordered_set *-- swappable_set
```

[swappable_set](swappable_set.md) _is an_ [ordered_set](ordered_set.md) where the items are swappable.
