#[derive(Debug)]
struct Node {
    data: i64,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn node(data: i64) -> Node {
        Node {
            left: None,
            right: None,
            data: data,
        }
    }
} 

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn create_node() {
        let node =  Node {
            data: 0x2f,
            left: None,
            right: None,
        };
        assert_eq!(node.data,  0x2f);
        assert!(node.left.is_none());
        assert!(node.right.is_none());
    }
    #[test]
    fn  create_node2(){
        let node = Node::node(0x2f);
        assert_eq!(node.data,  0x2f);
        assert!(node.left.is_none());
        assert!(node.right.is_none());
    }
}
