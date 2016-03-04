




int maxdepth_bst(bsttree *root)
{
  if (root == NULL)
    return 0;

  return 1 + max(maxdepth_bst(root->left), maxdepth_bst(root->right));
}


//divide and conquer
int mindepth_bst(bsttree *root)
{
  if (root == NULL)
    return 0;

  if (NULL == root->left)
  {
    return 1 + mindepth_bst(root->right);
  }

  if (NULL == root->right)
  {
    return 1+ mindepth_bst(root->left);
  }

  return 1 + min(mindepth_bst(root->left), mindepth_bst(root->right));
}


// recursive

void mindepth_bst1(bsttree *root, int &mindepth, int depth)
{
  if (root == NULL)
  {
    return;
  }

  if (root->left == NULL && root->right == NULL)
  {
    if (mindepth > depth)
    {
      mindepth = depth;
    }
    return;
  }

  mindepth_bst1(root->left, mindepth, depth+1);
  mindepth_bst1(root->right, mindepth, depth+1);

}

void mindepth_bst2(bsttree *root, int &mindepth, int depth)
{
  if (root == NULL)
  {
    return;
  }
  depth++;
  if (root->left == NULL && root->right == NULL)  
  {
    if (mindepth > depth)
    {
      mindepth = depth;
    }
    return;
  }
 
  mindepth_bst2(root->left, mindepth, depth);
  mindepth_bst2(root->right, mindepth, depth);
}

int minDepth_bst2(bsttree *root)
{
  int mindepth = INT_MAX;
  int depth = 0;
  if (root == NULL)
  {
    return 0;
  }
  mindepth_bst1(root, mindepth, depth);
  return mindepth;
}


void binaryTreePathSum_helper(bsttree *root, vector<int> set, vector<vector<int>> &result, int temp, int target)
{
  if (root == NULL)
  {
    return;
  }

  temp += root->val;
  set.push_back(temp);
  if (root->left == NULL && root->right == NULL)
  {
    if (temp == target)
    {
      result.push_back(set);
      return;
    }
  }
  binaryTreePathSum_helper(root->left, set, result, temp, target);
  binaryTreePathSum_helper(root->right, set, result, temp, target);
}

vector<vector<int>> binaryTreePathSum(bsttree *root, int target)
{
  int temp = 0;
  vector<vector<int>> result;
  vector<int> set;
  binaryTreePathSum_helper(root, set, result, temp, target);

  return result;
}

int hasPathSum_helper(bsttree*root, int tempsum, int sum)
{
  if (root == NULL)
  {
    return 0;
  }

  tempsum += root->val;

  if (root->left == NULL && root->right == NULL)
  {
    return (tempsum == sum);
  }

  return (hasPathSum_helper(root->left, tempsum, sum) || hasPathSum_helper(root->right, tempsum, sum));
}

int hasPathSum(bsttree* root, int sum)
{
  int tempsum = 0;
  return hasPathSum_helper(root, tempsum, sum);

}


int maxPathSum_anynode_helper(bsttree *root, int &maxsum)
{
  if (root == NULL)
  {
    return 0;
  }

  int leftmax = maxPathSum_anynode_helper(root->left, maxsum);
  int rightmax = maxPathSum_anynode_helper(root->right, maxsum);

  int throughmax = leftmax + rightmax + root->val;
  int singlepath_max = max(leftmax, rightmax) + root->val;

  maxsum = max(max(maxsum, throughmax), singlepath_max);

  return singlepath_max;
}

int maxPathSum_anynode(bsttree *root)
{
  int maxsum = INT_MIN;

  maxPathSum_anynode_helper(root, maxsum);

  return maxsum;
}


//[CareerCup] 4.9 All Paths Sum 
//4.9 You are given a binary tree in which each node contains a value.
//Design an algorithm to print all paths which sum to a given value.
//The path does not need to start or end at the root or a leaf.
void pathSumDFS(bsttree *root, int sum, int level, vector<int> path, vector<vector<int> >&result)
{
  if (NULL == root)
  {
    return;
  }

  path[level] = root->val;
  int tempsum = 0;
  vector<int>set;
  for (int i = level; i >= 0; i--)
  {
    set.push_back(path[i]);
    tempsum += path[i];
    if (tempsum == sum)
    {
      result.push_back(set);
      return;
    }
  }

  pathSumDFS(root->left,  sum, level+1, path, result);
  pathSumDFS(root->right, sum, level+1, path, result);
}

vector<vector<int> > pathSum(bsttree *root, int sum)
{
  vector<vector<int> >result;
  if (NULL == root)
  {
    return result;
  }
  int depth = maxdepth_bst(root);

  vector<int> path(depth, INT_MIN);

  pathSumDFS(root, sum, 0, path, result);

  return result;
}
