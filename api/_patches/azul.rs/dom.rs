    impl core::iter::FromIterator<Dom> for Dom {
        fn from_iter<I: IntoIterator<Item=Dom>>(iter: I) -> Self {
            use crate::vec::DomVec;
            let mut estimated_total_children = 0;
            let children = iter.into_iter().map(|c| {
                estimated_total_children += c.estimated_total_children + 1;
                c
            }).collect::<DomVec>();

            Dom {
                root: NodeData::div(),
                children,
                estimated_total_children,
            }
        }
    }

    impl core::iter::FromIterator<NodeData> for Dom {
        fn from_iter<I: IntoIterator<Item=NodeData>>(iter: I) -> Self {
            use crate::vec::DomVec;
            let children = iter.into_iter().map(|c| Dom { root: c, children: DomVec::new(), estimated_total_children: 0 }).collect::<DomVec>();
            let estimated_total_children = children.len();

            Dom {
                root: NodeData::div(),
                children: children,
                estimated_total_children,
            }
        }
    }

    impl core::iter::FromIterator<NodeType> for Dom {
        fn from_iter<I: core::iter::IntoIterator<Item=NodeType>>(iter: I) -> Self {
            iter.into_iter().map(|i| {
                let mut nd = NodeData::default();
                nd.node_type = i;
                nd
            }).collect()
        }
    }

    impl From<On> for AzEventFilter {
        fn from(on: On) -> AzEventFilter {
            on.into_event_filter()
        }
    }