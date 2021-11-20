#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}


impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None
        }
    }
}

use std::rc::Rc;
use std::cell::RefCell;


impl Solution {
    pub fn preorder_traversal(root: Option<Rc<RefCell<TreeNode>>>)
    -> Vec<i32> {
        let mut ans = vec![];
        let mut stack = vec![root];

        while let Some(node) = stack.pop() {
            if let Some(n) = node {
                ans.push(n.borrow().val);
                stack.push(n.borrow_mut().right.take());
                stack.push(n.borrow_mut().left.take());
            }
        }
        ans
    }
}



