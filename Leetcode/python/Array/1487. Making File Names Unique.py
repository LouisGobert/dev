from typing import List, Set


def get_next_available_extra_number(names: Set[str], base_name: str, start_at: int) -> int:
    extra_number = start_at
    while f"{base_name}({extra_number})" in names:
        extra_number += 1
    return extra_number


class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        new_names: List[str] = []
        new_names_set: Set[str] = set()
        next_available_name_extra: dict[str, int] = {}
        for name in names:
            if name in new_names:
                # Try to find next available number
                start_at = next_available_name_extra.get(name, 1)
                next_number = get_next_available_extra_number(new_names_set, name, start_at)
                next_available_name_extra[name] = next_number + 1
                new_name = f"{name}({next_number})"
                new_names.append(new_name)
                new_names_set.add(new_name)
            else:
                new_names.append(name)
                new_names_set.add(name)

        return new_names


if __name__ == "__main__":
    s = Solution()
    assert s.getFolderNames(["pes", "fifa", "gta", "pes(2019)"]) == ["pes", "fifa", "gta", "pes(2019)"]
    assert s.getFolderNames(["gta", "gta(1)", "gta", "avalon"]) == ["gta", "gta(1)", "gta(2)", "avalon"]
