## Assignment 1

### Que1 Explain the different applications of ML with domain name.

Computer Vision:
- Object Detection (e.g., self-driving cars detecting pedestrians, traffic signs)
- Image Classification (e.g., medical imaging for disease diagnosis) 
- Image Segmentation (e.g., augmented reality apps separating objects from background)
- Image Generation (e.g., creating artificial images for games, movies)

Natural Language Processing:
- Machine Translation (e.g., Google Translate)
- Sentiment Analysis (e.g., understanding opinions in product reviews)
- Text Summarization (e.g., condensing long documents into summaries)
- Conversational Agents (e.g., digital assistants like Siri, Alexa)

Recommender Systems:
- Product Recommendations (e.g., Amazon suggesting relevant products)
- Movie/Content Recommendations (e.g., Netflix's recommended shows)
- Social Media Feed Curation (e.g., Facebook/Twitter customizing your feed)

Reinforcement Learning: 
- Robotics (e.g., learning optimal movements through trial-and-error)
- Gaming (e.g., AI agents learning to beat human players)
- Resource Management (e.g., optimizing energy usage in smart grids)

Generative Models:
- Image Generation (e.g., creating artificial photos, artwork)
- Text Generation (e.g., language models for creative writing)  
- Music/Audio Generation (e.g., composing new songs, sound effects)


### Que2 Differentiate between supervised and unsupervised machine learning.

Supervised learning uses labeled training data to learn a function that maps inputs to desired outputs. The model is trained on example input-output pairs and learns to predict the correct output for new, unseen inputs. Common supervised learning tasks include classification and regression.

Unsupervised learning finds hidden patterns and structures in unlabeled data without any predefined output labels. The model learns the inherent structure of the data on its own. Typical unsupervised learning tasks include clustering, dimensionality reduction, and anomaly detection.

| Aspect | Supervised Learning | Unsupervised Learning |
|--------|---------------------|----------------------|
| Input Data | Labeled data with input-output pairs | Unlabeled data without predefined output |
| Goal | Learn a function that maps input to output | Discover hidden patterns or structures in data |
| Learning Process | Direct feedback guides the learning process | No explicit feedback; the model learns on its own |
| Common Algorithms | Linear Regression, Logistic Regression, Decision Trees, Support Vector Machines, Neural Networks | K-means Clustering, Hierarchical Clustering, Principal Component Analysis, Association Rules |
| Applications | Image Classification, Sentiment Analysis, Fraud Detection, Speech Recognition | Customer Segmentation, Anomaly Detection, Recommendation Systems, Dimensionality Reduction |
| Evaluation Metrics | Accuracy, Precision, Recall, F1-Score, Mean Squared Error | Silhouette Score, Davies-Bouldin Index, Calinski-Harabasz Index |

### Que3 What Are the Applications of Supervised Machine Learning in Modern Businesses?

<!-- Some key applications of supervised machine learning in modern businesses include: -->

- Sales forecasting: Predicting future sales based on historical data, market trends, etc.
- Customer churn prediction: Identifying customers likely to stop doing business, to enable proactive retention efforts
- Fraud detection: Flagging potentially fraudulent transactions in domains like banking and insurance  
- Sentiment analysis: Determining customer opinion from reviews, social media, support interactions
- Pricing optimization: Setting prices to maximize revenue or profit based on modeling customer behavior
- Predictive maintenance: Anticipating equipment failures to enable just-in-time maintenance and prevent unplanned downtime
- Credit scoring: Estimating the risk of lending to a potential borrower

<!-- Supervised learning excels at these kinds of prediction problems where there is labeled historical data to learn from. -->

### Que4 What is Machine Learning? What are issues in Machine Learning? Explain.

Machine learning is a branch of artificial intelligence that focuses on building systems that can learn and improve from experience without being explicitly programmed. ML algorithms build models based on sample data in order to make predictions or decisions on new data.

Some key issues and challenges in machine learning include:

- Data quality and quantity: ML requires large amounts of high-quality training data, which can be difficult and expensive to obtain. Insufficient, noisy, or biased data leads to poor model performance.

- Overfitting and underfitting: Models that are too complex can overfit, essentially memorizing noise in the training data and failing to generalize. Models that are too simple can underfit, failing to capture important patterns. Striking the right balance is crucial.

- Feature engineering: The success of ML models depends heavily on the quality of the input features. Determining the right features and representations is often a labor-intensive and domain-specific challenge. 

- Interpretability and explainability: Many high-performing ML models, like deep neural networks, are "black boxes" whose internal decision-making is opaque. This can be problematic in regulated domains or when trying to debug issues.

- Deployment and monitoring: Deploying ML models into production environments and monitoring their performance over time introduces a host of engineering and operational challenges beyond just building an accurate model.

<!-- Continued research aims to progressively address these issues and make ML more robust, efficient, and trustworthy. -->

### Que5 What are basic types of Data in Machine Learning? Explain in detail.

<!-- #### Basic Types of Data in Machine Learning -->
<!-- In the field of Machine Learning, understanding the different types of data is crucial for selecting appropriate algorithms, preprocessing techniques, and evaluation metrics. The question at hand is: "What are the basic types of data in Machine Learning? Explain in detail." -->

Data can be broadly categorized into two main types: Qualitative and Quantitative. Each of these types can be further subdivided based on their characteristics and properties.

##### Qualitative Data

Qualitative data represents attributes or characteristics that cannot be measured numerically. It is often descriptive in nature and deals with categories or labels. Qualitative data can be further classified into two subtypes:

1. **Nominal Data**: Nominal data consists of categories or labels that have no inherent order or ranking. Examples include gender (male, female), colors (red, blue, green), or types of fruits (apple, banana, orange). Nominal data is often represented using strings or labels.

2. **Ordinal Data**: Ordinal data also consists of categories or labels, but unlike nominal data, there is a natural order or ranking among the categories. However, the differences between the categories are not necessarily equal or measurable. Examples include educational levels (high school, bachelor's, master's, Ph.D.) or survey responses (strongly disagree, disagree, neutral, agree, strongly agree).

##### Quantitative Data

Quantitative data represents numerical values that can be measured and compared. It can be further divided into two subtypes based on the nature of the measurements:

1. **Interval Data**: Interval data consists of numerical values where the differences between the values are meaningful and consistent, but there is no true zero point. In other words, a value of zero does not indicate the absence of the measured attribute. Examples include temperature measured in Celsius or Fahrenheit, where a temperature of 0°C or 32°F does not mean the absence of temperature.

2. **Ratio Data**: Ratio data is similar to interval data but has a true zero point, indicating the absence of the measured attribute. Ratio data allows for meaningful ratios and comparisons between values. Examples include height, weight, age, or income, where a value of zero represents the absence of the attribute.

##### Discrete vs. Continuous Data

In addition to the qualitative and quantitative classifications, data can also be categorized as discrete or continuous:

1. **Discrete Data**: Discrete data consists of distinct, separate values that cannot be subdivided further. It is often represented by integers or whole numbers. Examples include the number of students in a class, the number of cars in a parking lot, or the number of defective products in a batch.

2. **Continuous Data**: Continuous data consists of values that can take on any value within a given range. It is often represented by real numbers and can be measured to a high degree of precision. Examples include height, weight, temperature, or time.

<!-- Understanding the different types of data is essential in Machine Learning because it influences the choice of algorithms, preprocessing techniques, and evaluation metrics. For example, certain algorithms, such as decision trees, can handle both qualitative and quantitative data, while others, like linear regression, are designed for quantitative data only. Additionally, the type of data determines the appropriate preprocessing steps, such as encoding categorical variables or scaling numerical features.

By correctly identifying and handling the different types of data, Machine Learning practitioners can develop more accurate and effective models, leading to better insights and predictions. -->

## Assignment 2

### Que1 Explain KNN Algorithm with suitable example.

The k-Nearest Neighbors (kNN) algorithm is a non-parametric, instance-based learning method used for classification and regression tasks in machine learning. It is a simple yet effective algorithm that relies on the principle of similarity between data points.

#### How kNN Works

The kNN algorithm works by finding the k most similar (nearest) data points to a given query point and then assigning the majority class (for classification) or the average value (for regression) of those k neighbors to the query point.

The steps involved in the kNN algorithm are as follows:

1. Choose the number of neighbors (k) and a distance metric (e.g., Euclidean, Manhattan, or Minkowski distance).
2. Calculate the distance between the query point and all the data points in the training set.
3. Sort the distances in ascending order and select the k nearest neighbors.
4. For classification: Assign the majority class among the k nearest neighbors to the query point.
   For regression: Assign the average value of the k nearest neighbors to the query point.

#### Example

Let's consider a simple example to illustrate how kNN works for classification. Suppose we have a dataset with two features (X1 and X2) and two classes (A and B). The dataset is as follows:

| X1 | X2 | Class |
|----|----|----|
| 1  | 2  | A  |
| 2  | 1  | A  |
| 3  | 1  | B  |
| 6  | 5  | B  |
| 7  | 5  | B  |

Now, let's say we have a query point (4, 3) and we want to classify it using kNN with k=3 and Euclidean distance.

1. Calculate the Euclidean distance between the query point and all the data points:

   $d = \sqrt{(x_1 - x_2)^2 + (y_1 - y_2)^2}$

   - Distance to (1, 2): $\sqrt{(4-1)^2 + (3-2)^2} = 3.16$
   - Distance to (2, 1): $\sqrt{(4-2)^2 + (3-1)^2} = 2.83$
   - Distance to (3, 1): $\sqrt{(4-3)^2 + (3-1)^2} = 2.24$
   - Distance to (6, 5): $\sqrt{(4-6)^2 + (3-5)^2} = 2.83$
   - Distance to (7, 5): $\sqrt{(4-7)^2 + (3-5)^2} = 3.61$

2. Sort the distances in ascending order and select the k=3 nearest neighbors:
   - (3, 1) with distance 2.24, Class B
   - (2, 1) with distance 2.83, Class A
   - (6, 5) with distance 2.83, Class B

3. The majority class among the 3 nearest neighbors is B (2 out of 3). Therefore, the query point (4, 3) is classified as class B.

#### Advantages and Disadvantages

Advantages of kNN:
- Simple to understand and implement
- No training phase required (lazy learning)
- Can handle multi-class classification problems
- Effective with small datasets

Disadvantages of kNN:
- Computationally expensive for large datasets (requires calculating distances to all data points)
- Sensitive to the choice of k and distance metric
- Sensitive to irrelevant features and feature scaling
- Memory-intensive (stores all training data)

<!-- In conclusion, the k-Nearest Neighbors algorithm is a simple and intuitive approach to classification and regression problems. It relies on the similarity between data points and assigns the majority class or average value of the k nearest neighbors to a query point. While it has its advantages, such as simplicity and effectiveness with small datasets, it also has limitations, particularly with large datasets and sensitivity to various factors. -->

### Que2 Explain SVM Algorithm in Detail.

Support Vector Machine (SVM) is a powerful supervised learning algorithm used for classification, regression, and outlier detection tasks. It aims to find the optimal hyperplane that maximally separates different classes in the feature space. SVMs are particularly effective in high-dimensional spaces and when the number of features is greater than the number of samples.

![SVM Diagram](./assignment%20-%20svm_image.png)

#### Linear SVM
In the simplest case, consider a binary classification problem with linearly separable data. Let the training dataset be $\{(\mathbf{x}_1, y_1), (\mathbf{x}_2, y_2), \ldots, (\mathbf{x}_n, y_n)\}$, where $\mathbf{x}_i \in \mathbb{R}^d$ is the feature vector and $y_i \in \{-1, 1\}$ is the corresponding class label.

The goal of linear SVM is to find a hyperplane defined by the equation $\mathbf{w}^T\mathbf{x} + b = 0$, where $\mathbf{w}$ is the normal vector to the hyperplane and $b$ is the bias term. The optimal hyperplane maximizes the margin, which is the distance between the hyperplane and the closest data points from each class.

The optimization problem for finding the optimal hyperplane can be formulated as:

$$
\begin{align*}
\min_{\mathbf{w}, b} \quad & \frac{1}{2} \|\mathbf{w}\|^2 \\
\text{subject to} \quad & y_i(\mathbf{w}^T\mathbf{x}_i + b) \geq 1, \quad i = 1, \ldots, n
\end{align*}
$$

This is a convex quadratic optimization problem that can be solved using quadratic programming techniques. The data points that lie on the margin are called support vectors, and they determine the position and orientation of the hyperplane.

#### Soft Margin SVM
In real-world scenarios, the data may not be perfectly linearly separable. Soft margin SVM allows for some misclassifications by introducing slack variables $\xi_i \geq 0$. The optimization problem becomes:

$$
\begin{align*}
\min_{\mathbf{w}, b, \xi} \quad & \frac{1}{2} \|\mathbf{w}\|^2 + C \sum_{i=1}^n \xi_i \\
\text{subject to} \quad & y_i(\mathbf{w}^T\mathbf{x}_i + b) \geq 1 - \xi_i, \quad i = 1, \ldots, n \\
& \xi_i \geq 0, \quad i = 1, \ldots, n
\end{align*}
$$

The parameter $C > 0$ controls the trade-off between maximizing the margin and minimizing the classification errors. A smaller $C$ allows for more misclassifications, while a larger $C$ enforces stricter classification.

#### Kernel SVM
For non-linearly separable data, SVM can be extended using the kernel trick. The idea is to map the input features into a higher-dimensional space where the data becomes linearly separable. This is achieved by replacing the dot product $\mathbf{x}_i^T\mathbf{x}_j$ with a kernel function $K(\mathbf{x}_i, \mathbf{x}_j)$.

Common kernel functions include:
- Linear kernel: $K(\mathbf{x}_i, \mathbf{x}_j) = \mathbf{x}_i^T\mathbf{x}_j$
- Polynomial kernel: $K(\mathbf{x}_i, \mathbf{x}_j) = (\gamma \mathbf{x}_i^T\mathbf{x}_j + r)^d$
- Radial Basis Function (RBF) kernel: $K(\mathbf{x}_i, \mathbf{x}_j) = \exp(-\gamma \|\mathbf{x}_i - \mathbf{x}_j\|^2)$

The choice of kernel function depends on the problem at hand and the nature of the data. The RBF kernel is a popular choice as it can handle complex non-linear decision boundaries and has fewer hyperparameters compared to the polynomial kernel.

#### Advantages and Disadvantages
SVMs have several advantages:
- Effective in high-dimensional spaces and when the number of dimensions exceeds the number of samples
- Memory-efficient since they use a subset of training points (support vectors)
- Versatile due to different kernel functions
- Robust to overfitting, especially with an RBF kernel

However, SVMs also have some disadvantages:
- The choice of kernel and regularization parameters can significantly impact performance
- Training can be slow for large datasets
- They don't directly provide probability estimates

#### Conclusion
Support Vector Machines are a powerful and versatile class of supervised learning algorithms. They aim to find the optimal hyperplane that maximally separates different classes in the feature space. SVMs can handle both linearly separable and non-linearly separable data using the kernel trick. While they have many advantages, such as effectiveness in high-dimensional spaces and robustness to overfitting, they can be sensitive to the choice of kernel and regularization parameters, and training can be slow for large datasets. Overall, SVMs are a valuable tool in the machine learning toolbox, particularly for complex but small- or medium-sized datasets.


### Que3 What is a logistic regression? Explain with suitable example.

Logistic regression is a statistical method for predicting binary outcomes (a variable that can take on one of two possible values, typically labeled "0" and "1", or "yes" and "no"). Despite its name, it is actually a classification algorithm rather than a regression algorithm.

Key concepts in logistic regression:

- Odds: The ratio of the probability of an event occurring to the probability of it not occurring.
- Log-Odds (Logit): The logarithm of the odds, which can take on any real value and is the quantity predicted by logistic regression.
- Sigmoid Function: A mathematical function that maps any real value to a value between 0 and 1, used to convert log-odds to probabilities.

The logistic regression model is defined as:

$$ log(\frac{p}{1-p}) = β_0 + β_1X_1 + ... + β_nX_n $$

where $p$ is the probability of the outcome, $X_1$ to $X_n$ are the predictor variables, and $β_0$ to $β_n$ are the coefficients estimated from the data.

The model is trained by maximizing the likelihood function, which quantifies how well the model fits the observed data. This is typically done using gradient descent optimization.

Example: Predicting customer churn

Imagine we want to predict whether a customer will churn (i.e., cancel their subscription) based on their demographic and usage data. Our target variable is binary: 1 if the customer churned, 0 if they didn't.

We could build a logistic regression model with predictors like:

- Age (numeric)
- Gender (binary, e.g. 0 for male, 1 for female)
- Monthly charges (numeric)
- Contract type (categorical, e.g. month-to-month, one year, two year)
- Total charges (numeric)

The model would learn coefficients for each predictor that maximize the likelihood of the observed churn outcomes. We could then use the model to predict the probability of churn for new customers based on their predictor values.

For instance, the model might learn that higher monthly charges and month-to-month contracts are associated with higher churn probability, while higher total charges (indicating a longer customer lifetime) are associated with lower churn probability.

Advantages of logistic regression:

- Simple to implement, interpret, and efficient to train
- Doesn't require input features to be scaled
- Can handle a mix of continuous and categorical predictors
- Outputs well-calibrated probabilities

Disadvantages:

- Presumes a linear relationship between predictors and log-odds of the outcome
- Requires each observation to be independent
- Can suffer from complete separation if a predictor perfectly separates the classes

<!-- Despite its limitations, logistic regression is a powerful and widely-used method for binary classification problems. It's often the go-to method before trying more sophisticated algorithms. -->

### Que4 What are Decision Trees? Explain with suitable example.

Decision Trees are a non-parametric supervised learning method used for both classification and regression tasks. They learn simple decision rules inferred from the data features to predict a target value.

A Decision Tree is a flowchart-like tree structure where:

- Each internal node represents a "test" on an attribute (e.g. whether a coin flip comes up heads or tails)
- Each branch represents the outcome of the test
- Each leaf node represents a class label (decision taken after computing all attributes)

The paths from root to leaf represent classification rules.

To make a prediction for a new instance, the tree is traversed from the root down to a leaf, testing the instance's attributes at each node and following the corresponding branch. The leaf reached at the end of this traversal gives the prediction.

Example: Predicting survival on the Titanic

Imagine we want to predict whether a passenger on the Titanic would have survived based on attributes like:

- Sex (male/female)
- Age (numeric)
- Passenger Class (1st, 2nd, 3rd)
- Fare (numeric)

A decision tree for this problem might look like:

```ass
                  Passenger Class?
                  /             \
                 /               \
                /                 \
               1st               Not 1st
               /                    |
              /                     |
             /                      |
            /                       |
         Sex?                    Age < 18?
         /   \                     /    \
        /     \                   /      \
       /       \                 /        \
    Female     Male            Yes         No
      |         |               |           |
      |         |               |           |
   Survived  Died           Survived      Died
```

This tree suggests that:

1. If a passenger was in 1st class and female, they likely survived.
2. If a passenger was in 1st class and male, they likely died.
3. If a passenger was not in 1st class and under 18, they likely survived.
4. If a passenger was not in 1st class and 18 or older, they likely died.

The tree is built by recursively selecting the attribute that best splits the data into the target classes, based on a metric like Gini impurity or information gain. This process continues until a stopping criterion is met, such as a maximum depth or a minimum number of instances per leaf.

Advantages of Decision Trees:

- Simple to understand and interpret
- Requires little data preparation (no need for scaling or centering)
- Able to handle both numerical and categorical data
- Performs well even if assumptions for other models (like linearity) are not met

Disadvantages:

- Prone to overfitting, especially if the tree is deep
- Can be unstable - small variations in data can result in a completely different tree
- Greedy algorithms cannot guarantee to return the globally optimal decision tree
- Biased towards features with many levels (like IDs)

Decision Trees are the building blocks for powerful ensemble methods like Random Forests and Gradient Boosting Machines. They provide a great starting point for understanding and solving classification and regression problems.

### Que5 Explain Naïve Bayes with suitable Example.

Naive Bayes is a probabilistic machine learning algorithm used for classification tasks. It's based on Bayes' theorem with the naive assumption of conditional independence between every pair of features given the value of the class variable.

Bayes' theorem describes the probability of an event based on prior knowledge of conditions that might be related to the event. In mathematical terms, it's expressed as:

$$P(A|B) = \frac{P(B|A) * P(A)}{P(B)}  $$

where A and B are events and P(B) ≠ 0.

- $P(A \vert B)$ is the posterior probability: the likelihood of event A occurring given that B is true.
- $P(B \vert A)$ is the likelihood: the probability of observing event B given that A is true.
- $P(A)$ is the prior probability: the probability of event A occurring.
- $P(B)$ is the marginal probability: the probability of event B occurring.

<!-- In spite of their naive design and apparently oversimplified assumptions, Naive Bayes classifiers have worked quite well in many complex real-world situations. -->

Example: The dataset has two features: color (red or yellow) and shape (round or elongated). The goal is to classify the fruits into two categories: apple or banana.

Given:
- Apples are red and round.
- Bananas are yellow and elongated.

We have a new fruit with the following features:
- Color: red
- Shape: round

We want to determine the probability of this fruit being an apple or a banana.

Step 1: Calculate the prior probabilities.
$P(Apple) = 0.5$ (assuming equal probability for both classes)
$P(Banana) = 0.5$

Step 2: Calculate the likelihoods.
$P(Red \vert Apple) = 1.0$ (all apples in the dataset are red)
$P(Round \vert Apple) = 1.0$ (all apples in the dataset are round)
$P(Yellow \vert Banana) = 1.0$ (all bananas in the dataset are yellow)
$P(Elongated \vert Banana) = 1.0$ (all bananas in the dataset are elongated)

Step 3: Apply Bayes' theorem to calculate the posterior probabilities.

$$ P(Apple \vert  Red, Round) = \frac{P(Red|Apple) × P(Round|Apple) × P(Apple)}{P(Red, Round)}$$

$$ P(Banana \vert Red, Round) = \frac{P(Red|Banana) × P(Round|Banana) × P(Banana)}{P(Red, Round)} $$

Since the denominator $P(Red, Round)$ is the same for both classes, we can ignore it for comparison purposes.

$$P(Apple \vert Red, Round) ∝ 1.0 × 1.0 × 0.5 = 0.5$$
$$P(Banana \vert Red, Round) ∝ 0.0 × 0.0 × 0.5 = 0.0$$

<sup>∝ is proportionality</sup>

Step 4: Compare the posterior probabilities and classify the fruit.
The probability of the fruit being an apple (0.5) is higher than the probability of it being a banana (0.0). Therefore, the Naïve Bayes classifier would classify this fruit as an apple.

In this example, the Naïve Bayes algorithm assumes that the color and shape features are independent, which simplifies the calculations. In practice, the algorithm can handle more features and classes, and the probabilities are estimated from the training data.

## Garbage

#### Answer 1

Support Vector Machines (SVMs) are a powerful and versatile class of supervised learning algorithms used for classification, regression, and outlier detection. SVMs aim to find the hyperplane in an N-dimensional space that maximally separates data points of different classes.

Key concepts in SVMs:

- Hyperplane: A subspace of dimension N-1 that divides an N-dimensional space. In 2D, a hyperplane is a line; in 3D, it's a plane.
- Support Vectors: The data points closest to the hyperplane, which influence its position and orientation. The distance between the support vectors and the hyperplane is called the margin.
- Kernel: A function that transforms the input data into a higher-dimensional space where it may be linearly separable. This allows SVMs to model non-linear decision boundaries.

The SVM algorithm works as follows:

1. Map the training data into a high-dimensional feature space.
2. Find the hyperplane that maximizes the margin between classes in this space.
3. Choose the hyperplane that correctly separates most training examples (the optimal margin classifier).
4. If no separating hyperplane exists, soften the margin to allow some misclassifications (using a regularization parameter C).
5. Classify new examples based on which side of the hyperplane they fall.

For non-linearly separable data, SVMs use the kernel trick. Instead of explicitly transforming the data to a high-dimensional space (which can be computationally expensive), a kernel function is used to compute the inner products between pairs of data points in the feature space. This allows the SVM to fit a linear hyperplane in the transformed space, which corresponds to a non-linear decision boundary in the original space.

Some common kernel functions:

- Linear: No transformation, used when data is linearly separable
- Polynomial: Allows modeling feature interactions up to the specified degree
- Radial Basis Function (RBF): Maps data to an infinite-dimensional space, can fit complex decision boundaries
- Sigmoid: Equivalent to a two-layer neural network

SVMs have several advantages:

- Effective in high-dimensional spaces and when the number of dimensions exceeds the number of samples
- Memory-efficient since they use a subset of training points (support vectors) 
- Versatile due to different kernel functions
- Robust to overfitting, especially with an RBF kernel

However, SVMs can be sensitive to the choice of kernel and regularization parameters, and training can be slow for large datasets. They also don't directly provide probability estimates.

Overall, SVMs are a powerful tool in the machine learning toolbox, particularly for complex but small- or medium-sized datasets.

#### Answer 2

<!-- # Support Vector Machine (SVM) Algorithm

## Question
Explain Support Vector Machine Algorithm in Detail. -->

Support Vector Machine (SVM) is a supervised machine learning algorithm used for classification and regression tasks. It aims to find the optimal hyperplane that maximally separates the different classes in the feature space. SVMs are particularly effective in high-dimensional spaces and when the number of features is greater than the number of samples.

##### Linear SVM
In the simplest case, consider a binary classification problem with linearly separable data. Let the training dataset be $\{(\mathbf{x}_1, y_1), (\mathbf{x}_2, y_2), \ldots, (\mathbf{x}_n, y_n)\}$, where $\mathbf{x}_i \in \mathbb{R}^d$ is the feature vector and $y_i \in \{-1, 1\}$ is the corresponding class label.

The goal of linear SVM is to find a hyperplane defined by the equation $\mathbf{w}^T\mathbf{x} + b = 0$, where $\mathbf{w}$ is the normal vector to the hyperplane and $b$ is the bias term. The optimal hyperplane maximizes the margin, which is the distance between the hyperplane and the closest data points from each class.

The optimization problem for finding the optimal hyperplane can be formulated as:

$$
\begin{align*}
\min_{\mathbf{w}, b} \quad & \frac{1}{2} \|\mathbf{w}\|^2 \\
\text{subject to} \quad & y_i(\mathbf{w}^T\mathbf{x}_i + b) \geq 1, \quad i = 1, \ldots, n
\end{align*}
$$

This is a convex quadratic optimization problem that can be solved using quadratic programming techniques. The data points that lie on the margin are called support vectors, and they determine the position and orientation of the hyperplane.

##### Soft Margin SVM
In real-world scenarios, the data may not be perfectly linearly separable. Soft margin SVM allows for some misclassifications by introducing slack variables $\xi_i \geq 0$. The optimization problem becomes:

$$
\begin{align*}
\min_{\mathbf{w}, b, \xi} \quad & \frac{1}{2} \|\mathbf{w}\|^2 + C \sum_{i=1}^n \xi_i \\
\text{subject to} \quad & y_i(\mathbf{w}^T\mathbf{x}_i + b) \geq 1 - \xi_i, \quad i = 1, \ldots, n \\
& \xi_i \geq 0, \quad i = 1, \ldots, n
\end{align*}
$$

The parameter $C > 0$ controls the trade-off between maximizing the margin and minimizing the classification errors. A smaller $C$ allows for more misclassifications, while a larger $C$ enforces stricter classification.

##### Kernel SVM
For non-linearly separable data, SVM can be extended using the kernel trick. The idea is to map the input features into a higher-dimensional space where the data becomes linearly separable. This is achieved by replacing the dot product $\mathbf{x}_i^T\mathbf{x}_j$ with a kernel function $K(\mathbf{x}_i, \mathbf{x}_j)$.

Common kernel functions include:
- Linear kernel: $K(\mathbf{x}_i, \mathbf{x}_j) = \mathbf{x}_i^T\mathbf{x}_j$
- Polynomial kernel: $K(\mathbf{x}_i, \mathbf{x}_j) = (\gamma \mathbf{x}_i^T\mathbf{x}_j + r)^d$
- Radial Basis Function (RBF) kernel: $K(\mathbf{x}_i, \mathbf{x}_j) = \exp(-\gamma \|\mathb