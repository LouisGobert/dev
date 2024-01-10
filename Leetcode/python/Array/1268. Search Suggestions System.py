from typing import List


class Solution:
    def filters(self, products: List[str], seq: str) -> List[str]:
        return list(filter(lambda s: s.startswith(seq), products))

    def third_most_commen(self, products: List[str]) -> List[str]:
        if len(products) <= 3:
            return list(sorted(products))

        return list(sorted(products))[:3]

    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        result: List[List[str]] = []

        subresult: List[str] = []
        start_seq = ""
        for letter in searchWord:
            start_seq += letter
            products = self.filters(products, start_seq)
            result.append(self.third_most_commen(products))

        return result


if __name__ == "__main__":
    s = Solution()
    assert s.suggestedProducts(["mobile", "mouse", "moneypot", "monitor", "mousepad"], searchWord="mouse") == [
        ["mobile", "moneypot", "monitor"],
        ["mobile", "moneypot", "monitor"],
        ["mouse", "mousepad"],
        ["mouse", "mousepad"],
        ["mouse", "mousepad"],
    ]
    assert s.suggestedProducts(["bags", "baggage", "banner", "box", "cloths"], "bags") == [
        ["baggage", "bags", "banner"],
        ["baggage", "bags", "banner"],
        ["baggage", "bags"],
        ["bags"],
    ]
