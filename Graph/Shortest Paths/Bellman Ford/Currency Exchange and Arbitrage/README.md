# Resources
* See this comment for details:
  * https://leetcode.com/discuss/interview-question/1647092/Coinbase-or-Virtual-On-site-or-Interview-Questions/1195611
* [Blog] Graph algorithms and currency arbitrage, part 1 and 2
  * https://reasonabledeviations.com/2019/03/02/currency-arbitrage-graphs/
  * https://reasonabledeviations.com/2019/04/21/currency-arbitrage-graphs-2/
* Linkedin
  * https://www.linkedin.com/feed/update/urn:li:activity:7418275911759958016/


# Types of question
### Currency Arbitrage
* For currency arbitrage, you find negative edge cycle, and to do that, yes, you need to use bellman ford. You can take negative logarithm of edge-weights and find shortest path.
### Currency Exchange
* This is a backtracking question. You try all paths from source to destination and find maximal product.
* This question is almost like the "Evaluate division" leetcode question.


# Currency Exchange vs Currency Arbitrage

#### Currency Exchange
- **Definition**: The process of converting one currency into another at the prevailing exchange rate, typically for practical purposes like travel, trade, or investments.
- **Objective**: To facilitate transactions that require a different currency.
- **Mechanism**:
  - Individuals or businesses exchange money through banks, currency exchange services, or online platforms.
  - The transaction is based on the current exchange rate, which is influenced by market demand, central bank policies, and geopolitical factors.
- **Example**: A traveler exchanges USD for EUR at an airport to use during a European trip.
- **Risk**: Minimal if the transaction is one-off, though fluctuations in exchange rates can lead to losses if the timing is poor.
- **Participants**: Tourists, international businesses, and investors.

---

#### Currency Arbitrage
- **Definition**: A trading strategy that exploits price differences of the same currency in different markets to make a profit.
- **Objective**: To profit from discrepancies in exchange rates across different currency markets or platforms.
- **Mechanism**:
  - Traders identify differences in currency prices between markets or brokers.
  - They simultaneously buy and sell currencies to lock in the profit from the price spread.
  - Can be executed using advanced algorithms or manual trading.
- **Example**: 
  - A trader notices that 1 USD = 0.85 EUR on Platform A and 1 USD = 0.87 EUR on Platform B.
  - The trader buys EUR on Platform A and sells it on Platform B, earning a profit from the difference.
- **Risk**: Low if executed properly, but can be affected by transaction costs, execution delays, or market liquidity.
- **Participants**: Professional Forex traders, hedge funds, and institutions using sophisticated trading tools.

#### Key difference

| Aspect                | Currency Exchange                         | Currency Arbitrage                      |
|-----------------------|-------------------------------------------|-----------------------------------------|
| **Purpose**           | Practical use (travel, trade)            | Profit-making through price differences |
| **Complexity**        | Simple                                   | Complex and requires market analysis    |
| **Participants**      | General public, businesses               | Professional traders, financial firms   |
| **Risk**              | Minimal                                  | Low to moderate (depends on execution) |
| **Tools Needed**      | Basic exchange services                  | Advanced trading platforms, algorithms  |

---
