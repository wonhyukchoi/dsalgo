class Test {
    constructor(){}

    assertEqual(x: number, y:number) {
        if (x != y)
            throw new Error("Algorithm failed.")
    }

    testDriver(numArr: number[], nonexistentValues: number[]): void {
        for (const toSearch of numArr) {
            const result: number = binarySearch(numArr, toSearch);
            const expected = toSearch;
            this.assertEqual(result, expected);
        }
        const cannotFind: number = -1;
        for (const dneValue of nonexistentValues) {
            const result: number = binarySearch(numArr, dneValue);
            this.assertEqual(result, cannotFind);
        }
    }

    runTests() {
        this.testDriver([1,2,3,4,5], []);
        this.testDriver([1,2,3,4,5], [-1,6,10,77,-5]);
        this.testDriver([0,2,4,6,8,11,15,19,21], [1,3,5,7,12]);
    }
}

function binarySearch(arr: number[], val: number): number {
    return val;
}

const test: Test = new Test()
test.runTests()